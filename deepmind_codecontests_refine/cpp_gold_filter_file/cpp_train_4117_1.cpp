#include <bits/stdc++.h>
using namespace std;
string R;
string S;
int C[10];
int X[10];
int L;
void Main() {
  cin >> R >> S;
  L = ((int)(R).size());
  if (L == 2) {
    (void)printf("%c\n", R[R[0] == '1' ? 1 : 0]);
    return;
  }
  for (auto&& c : R) C[c - '0']++;
  for (auto&& c : S) X[c - '0']++;
  int a = L + 1;
  int d[10] = {0};
  int e[10] = {0};
  while (a) {
    a--;
    memset(d, 0, sizeof(d));
    int b = a;
    int da = 0;
    while (b) {
      d[b % 10]++;
      b /= 10;
      da++;
    }
    int ok = true;
    for (int i = 0; i < (10); i++) {
      if (d[i] + X[i] > C[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    if (L - da != a) continue;
    int k = 0;
    for (int i = 0; i < (10); i++) {
      e[i] = C[i] - d[i] - X[i];
      k += e[i];
    }
    int s0 = S[0] - '0';
    string top(S);
    for (int i = 0; i < (10); i++) {
      char c = '0' + i;
      for (int j = 0; j < (e[i]); j++) {
        top += c;
      }
    }
    string bet;
    int x = -1;
    if (e[0]) {
      for (int i = (1); i < (10); i++)
        if (e[i]) {
          x = i;
          bet += '0' + i;
          break;
        }
    }
    for (int i = 0; i < (10); i++) {
      char c = '0' + i;
      for (int j = 0; j < (e[i] - (x == i ? 1 : 0)); j++) {
        bet += c;
      }
    }
    bool bd = 0, ad = 0;
    string before, after;
    int p = -1;
    for (int i = 0; i < (k); i++) {
      char c = bet[i];
      int ci = c - '0';
      if (!bd && ci >= s0 && !(e[0] && i == 0)) {
        before += S;
        bd = 1;
      }
      if (!ad && p >= s0 && ci != s0 && !(e[0] && i == 1)) {
        after += S;
        ad = 1;
      }
      before += c;
      after += c;
      p = ci;
    }
    if (!bd) before += S;
    if (!ad) after += S;
    if (before[0] == '0') before[0] = 'z';
    if (after[0] == '0') after[0] = 'z';
    if (top[0] == '0') top[0] = 'z';
    if (top < before && top < after)
      cout << top;
    else if (before < after)
      cout << before;
    else
      cout << after;
    cout << endl;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  Main();
  return 0;
}
