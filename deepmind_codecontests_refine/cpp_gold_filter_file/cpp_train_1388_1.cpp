#include <bits/stdc++.h>
using namespace std;
const int prime[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                       43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
const int mod[5] = {9699690, 1348781387, 600662303, 33984931, 8633};
int N, M, radix, nz, len[17], pw[17][30];
long long a[10010], cc, rem;
string pat;
vector<long long> dp[17][5];
int pow(int a, int p) {
  if (p == 0) return 1;
  int tmp = pow(a, p >> 1);
  tmp *= tmp;
  if (p & 1) tmp *= a;
  return tmp;
}
void prepare() {
  long long pww;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%I64d", &a[i]);
  scanf("%d", &M);
  for (int d = 2; d <= 16; d++) {
    len[d] = 1, pww = d;
    while (pww < N) pww *= d, len[d]++;
    int sz = pow(d + 1, len[d]);
    for (int m = 0; m < 5; m++) dp[d][m].resize(sz + 10, -1);
  }
  for (int d = 2; d <= 16; d++)
    for (int w = 1, i = 0; i < len[d]; i++) pw[d][i] = w, w *= (d + 1);
}
inline int deal(char x, int d) {
  if (x == '?') return d;
  if (x <= '9') return x - '0';
  return 10 + (x - 'A');
}
inline long long rec(int d, int m, int mask) {
  long long &ret = dp[d][m][mask];
  if (ret != -1) return ret;
  ret = 1;
  int need = 0;
  for (int tMask = mask; need < len[d] && tMask % (d + 1) != d;
       tMask /= (d + 1), need++)
    ;
  if (need < len[d]) {
    mask -= d * pw[d][need];
    for (int x = 0; x < d; x++)
      ret = ret * rec(d, m, mask + x * pw[d][need]) % mod[m];
  } else {
    long long id = 0;
    for (int i = 0; i < len[d]; i++, mask /= (d + 1))
      id = id * d + (mask % (d + 1));
    ret = id < N ? a[id] % mod[m] : 1;
  }
  return ret;
}
int main() {
  int mask, ok;
  prepare();
  while (M--) {
    cin >> radix >> pat >> cc;
    nz = 0;
    while (pat[nz] == '0' || pat[nz] == '?') nz++;
    if (pat.size() - nz > len[radix]) {
      for (int i = 0; i < 26; i++)
        if (i == 25)
          puts("-1");
        else if ((cc + 1) % prime[i] == 0) {
          printf("%d\n", prime[i]);
          break;
        }
      continue;
    }
    if (pat.size() > len[radix])
      pat = pat.substr(pat.size() - len[radix], pat.size());
    while (pat.size() < len[radix]) pat = "0" + pat;
    mask = ok = 0;
    for (int i = 0, d = 1; i < len[radix]; i++, d *= (radix + 1))
      mask += deal(pat[i], radix) * d;
    for (int m = 0, pi = 0, pj; m < 5 && !ok; m++, pi = pj) {
      rem = rec(radix, m, mask);
      for (pj = pi; mod[m] % prime[pj] == 0; pj++)
        if ((rem + cc) % prime[pj] == 0) {
          printf("%d\n", prime[pj]);
          ok = 1;
          break;
        }
    }
    if (!ok) puts("-1");
  }
  return 0;
}
