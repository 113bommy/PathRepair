#include <bits/stdc++.h>
using namespace std;
const int SI = 5e5 + 100;
const long long mod = 1e9 + 7;
struct KMP {
  int Next[500005];
  char T[500005];
  int tlen;
  void getNext() {
    tlen = strlen(T);
    int j, k;
    j = 0;
    k = -1;
    Next[0] = -1;
    while (j < tlen) {
      if (k == -1 || T[j] == T[k])
        Next[++j] = ++k;
      else
        k = Next[k];
    }
  }
} ST;
char S[SI];
int cnt[10];
int main() {
  cin >> S >> ST.T;
  ST.getNext();
  int tl = ST.tlen;
  int l = strlen(S);
  for (int i = 0; i < l; i++) cnt[S[i] - '0']++;
  int ad = 0;
  while (cnt[0] + cnt[1] > 0) {
    if (cnt[ST.T[ad] - '0'] > 0) {
      cout << ST.T[ad];
      cnt[ST.T[ad] - '0']--;
      ad++;
      if (ad == ST.tlen) ad = ST.Next[ad];
    } else {
      while (cnt[0]--) cout << 0;
      while (cnt[1]--) cout << 1;
      break;
    }
  }
  return 0;
}
