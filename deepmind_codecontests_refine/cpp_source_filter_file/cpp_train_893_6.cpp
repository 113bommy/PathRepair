#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int vec[10];
int L[19], R[19];
int cnt2 = 0, cnt3;
void go(int nxt, int sum) {
  if (nxt == 10 && sum == 19) {
    cnt2++;
    bool ok = 0;
    int vec2[10];
    for (int i = 0; i < 10; i++) vec2[i] = vec[i];
    for (int i = 0; i < 19; i++) {
      if (L[i] == R[i]) {
        if (vec2[L[i]] == 0) return;
        vec2[L[i]]--;
      } else {
        for (int ii = L[i] + 1; ii < R[i]; ii++) {
          if (vec2[ii] > 0) {
            cnt++;
            return;
          }
        }
        int c[19], e[19], d = 0;
        if (vec2[R[i]] == 0) goto tugi;
        for (int ii = 0; ii < 10; ii++)
          for (int j = (ii == R[i] ? 1 : 0); j < vec2[ii]; j++) {
            c[d++] = ii;
          }
        for (int ii = i + 1; ii < 19; ii++) {
          if (R[ii] < c[ii - i - 1]) goto tugi;
          if (R[ii] < c[ii - i - 1]) {
            cnt++;
            return;
          }
        }
        cnt++;
        return;
      tugi:;
        d = 0;
        if (vec2[L[i]] == 0) return;
        for (int ii = 9; ii >= 0; ii--)
          for (int j = (ii == L[i] ? 1 : 0); j < vec2[ii]; j++) {
            e[d++] = ii;
          }
        for (int ii = i + 1; ii < 19; ii++) {
          if (L[ii] > e[ii - i - 1]) return;
          if (L[ii] < e[ii - i - 1]) {
            cnt++;
            return;
          }
        }
        cnt++;
        return;
      }
    }
    cnt++;
    return;
  } else if (nxt == 10)
    return;
  int c = 0;
  while (sum + c <= 19) {
    vec[nxt] = c;
    if (nxt + 1 != 10 || sum + c == 19) go(nxt + 1, sum + c);
    c++;
  }
}
int main() {
  long long LL, RR;
  cin >> LL >> RR;
  for (int i = 0; i < 19; i++) {
    L[18 - i] = LL % 10;
    LL /= 10;
    R[18 - i] = RR % 10;
    RR /= 10;
  }
  go(0, 0);
  cout << cnt << endl;
}
