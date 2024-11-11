#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &o, vector<T> &vec) {
  cout << "[";
  for (int i = 0; i < ((int)(vec).size()); i++) {
    if (i) cout << ", ";
    cout << vec[i];
  }
  cout << "]";
  return o;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &o, pair<T1, T2> &pair) {
  cout << "(" << pair.first << ", " << pair.second << ")";
  return o;
}
const long long MX = 312312;
const long long SQMX = 1000;
const long long MD = 1000000007;
long long N;
vector<long long> ip;
bool isp[MX];
vector<long long> prime;
long long sm[MX], tmp[MX];
long long C[MX];
long long fac[MX];
long long ps[MX];
long long fp(long long a, long long b) {
  if (!b) return 1 % MD;
  long long ret = fp(a * a % MD, b / 2);
  if (b & 1) ret = ret * a % MD;
  return ret;
}
inline long long rev(long long a) { return fp(a, MD - 2); }
void pre() {
  fill(isp + 2, isp + MX, true);
  for (long long i = 0; i < MX; i++) {
    if (isp[i]) {
      prime.push_back(i);
      for (long long j = i + i; j < MX; j += i) {
        isp[j] = false;
      }
    }
  }
  fac[0] = 1;
  for (long long i = 1; i <= N - 1; i++) fac[i] = fac[i - 1] * i % MD;
  for (long long i = 0; i <= N - 1; i++)
    C[i] = fac[N - 1] * rev(fac[i]) % MD * rev(fac[N - i - 1]) % MD;
  for (long long i = 0; i <= N - 1; i++) {
    ps[i + 1] = ps[i] + C[i];
  }
}
int32_t main() {
  cin >> N;
  pre();
  ip.resize(N);
  for (long long i = 0; i < N; i++) {
    cin >> ip[i];
  }
  long long ans = 0;
  for (long long i = 0; i < ((long long)(prime).size()); i++) {
    long long p = prime[i];
    if (p > SQMX) break;
    fill(tmp, tmp + N, 0);
    for (long long j = 0; j < N; j++) {
      long long t = 0, &a = ip[j];
      while (a % p == 0) {
        a /= p;
        t++;
      }
      tmp[j] = t;
    }
    sort(tmp, tmp + N);
    for (long long j = 0; j < N; j++) sm[j] += tmp[j];
  }
  sort(ip.begin(), ip.end());
  for (long long i = 0, j = 0; i < N; i = j) {
    while (ip[j] == ip[i]) j++;
    if (ip[i] == 0) continue;
    long long c = j - i;
    for (long long k = 0; k < c; k++) {
      sm[N - k - 1]++;
    }
  }
  for (long long j = 0; j < N; j++) {
    long long f1 = ps[j] - ps[0], f2 = ps[N] - ps[j + 1];
    long long f = f1 - f2;
    f = (f + MD) % MD;
    ans += f * sm[j];
    ans %= MD;
  }
  cout << ans << endl;
  return 0;
}
