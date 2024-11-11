#include <bits/stdc++.h>
using namespace std;
enum { MAXC = 400010 * 2 };
char str[MAXC], res[MAXC];
int mlen[MAXC];
int M;
char getNxt(const int &mpos, int i, char ch) {
  for (; ch <= 'z'; ++ch) {
    int mcen = mpos, tm = mlen[mcen];
    if (!(mcen - i >= 0 && str[mcen - i] == ch)) {
      int ncen;
      for (ncen = mcen + 1; ncen <= (i - 1) * 2 && mcen * 2 - ncen >= 0;
           ncen++) {
        if (mlen[mcen * 2 - ncen] + (ncen - 1) / 2 >= i - 1 && ncen - i >= 0 &&
            str[ncen - i] == ch) {
          tm = min(mlen[mcen * 2 - ncen], i - 1 - (ncen - 1) / 2);
          mcen = ncen;
          break;
        }
      }
      if (mcen != ncen) {
        tm = 0;
        if (str[i - 1] == ch)
          mcen = i * 2 - 1;
        else
          mcen = i * 2;
      }
    }
    if (tm * 2 - ((mcen & 1) ^ 1) + 2 < M) break;
  }
  return ch;
}
void solve(int &mcen, int i, char ch) {
  if (!(mcen - i >= 0 && str[mcen - i] == ch)) {
    int ncen;
    for (ncen = mcen + 1; mcen * 2 - ncen >= 0; ncen++) {
      mlen[ncen] = min(mlen[mcen * 2 - ncen], i - 1 - (ncen - 1) / 2);
      if (mlen[ncen] + (ncen - 1) / 2 == i - 1 && ncen - i >= 0 &&
          str[ncen - i] == ch) {
        mcen = ncen;
        break;
      }
    }
    if (mcen != ncen) {
      mlen[i * 2 - 1] = mlen[i * 2] = 0;
      if (str[i - 1] == ch)
        mcen = i * 2 - 1;
      else
        mcen = i * 2;
    }
  }
  if (mlen[mcen] * 2 - ((mcen & 1) ^ 1) + 2 < M) {
    ++mlen[mcen];
  }
}
char bak[MAXC];
bool Csolve(int n, int lsti) {
  char ch;
  copy(bak, bak + n, str);
  int mpos = 0;
  mlen[mpos] = 0;
  int i;
  for (i = 0; i < lsti; i++) {
    if (getNxt(mpos, i, str[i]) != str[i]) return false;
    solve(mpos, i, str[i]);
  }
  bool flag = true;
  for (i = lsti; i < n; i++) {
    if (flag) {
      ch = getNxt(mpos, i, str[i] + 1);
      if (ch > 'z')
        ch = getNxt(mpos, i, str[i]);
      else
        flag = false;
    } else
      ch = getNxt(mpos, i, 'a');
    if (ch > 'z') return false;
    solve(mpos, i, str[i] = ch);
  }
  return true;
}
int main() {
  scanf("%d", &M);
  scanf("%s", str);
  memcpy(bak, str, sizeof(bak));
  int n = strlen(str), left = 0, right = n;
  while (left < right) {
    int mid = (left + right) >> 1;
    if (Csolve(n, mid))
      left = mid + 1;
    else
      right = mid;
  }
  if (left == 0)
    puts("Impossible");
  else {
    Csolve(n, left - 1);
    puts(str);
  }
  return 0;
}
