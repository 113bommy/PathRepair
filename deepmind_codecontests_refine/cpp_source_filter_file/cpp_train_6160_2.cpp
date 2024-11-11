#include <bits/stdc++.h>
using namespace std;
const long long N = 10000100;
vector<int> v[30];
long long d[30] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                   43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
long long pri[4000100];
long long cnt;
bool b[N];
long long n, m;
long long power(long long a, long long b, long long c) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return ret;
}
void getp() {
  for (long long i = 2; i <= 2000000; i++) {
    if (!b[i]) {
      pri[++cnt] = i;
      for (long long j = 0; j < 25; j++)
        if (i >= m && (i - 1) % d[j] == 0) v[j].push_back(i);
    }
    for (long long j = 1; 1ll * i * pri[j] <= 2000000 && j <= cnt; j++) {
      b[i * pri[j]] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
long long f1[50], f2[50];
string s1, s2;
void solve(long long w) {
  memset(f1, 0, sizeof(f1));
  for (long long i = 0; i < n; i++) f1[i % d[w]] += s1[i] - s2[i];
  long long xx = v[w].size();
  for (long long i = 0; i < xx; i++) {
    long long p = v[w][i];
    for (long long j = 2; j < p - 2; j++) {
      long long kk = power(j, (p - 1) / d[w], p);
      if (kk != 1) {
        for (long long ww = 1; ww <= d[w]; ww++) {
          long long l = power(kk, ww, p);
          if (l < 2 || l > p - 2) continue;
          long long tmp = 1, ret1 = 0;
          for (long long k = 0; k < d[w]; k++) {
            ret1 = (ret1 + tmp * f1[k]) % p;
            tmp = tmp * l % p;
          }
          if (ret1 < 0) ret1 += p;
          if (ret1 == 0) {
            printf("%I64d %I64d\n", p, l);
            exit(0);
          }
        }
        break;
      }
    }
  }
}
int main() {
  cin >> n >> m;
  cin >> s1 >> s2;
  getp();
  for (long long j = 0; j < 25; j++) solve(j);
  return 0;
}
