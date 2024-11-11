#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &s, const pair<A, B> &p) {
  return s << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &c) {
  s << "[ ";
  for (auto it : c) s << it << " ";
  s << "]";
  return s;
}
const long long MAXN = 10000000;
const int MAXL = 20;
long long N;
bool isp[MAXN];
int pcnt[MAXN];
vector<int> primes;
void pre() {
  for (int i = 2; i < MAXN; i++) isp[i] = true;
  for (int i = 2; i < MAXN; i++) {
    if (!isp[i]) continue;
    primes.push_back(i);
    for (int j = 2 * i; j < MAXN; j += i) isp[j] = false;
  }
  pcnt[0] = 0;
  for (int i = 1; i < MAXN; i++) pcnt[i] = pcnt[i - 1] + isp[i];
}
long long prime_count(long long lim);
long long phi(long long m, int n) {
  if (m <= 0) return 0;
  if (n == 0) return m;
  if (primes[n - 1] * primes[n - 1] >= m) return prime_count(m) - n + 1;
  return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
}
long long prime_count(long long lim) {
  if (lim < MAXN) return pcnt[lim];
  long long m3 = 1, m2 = 1;
  while (m3 * m3 * m3 <= lim) m3++;
  while (m2 * m2 <= lim) m2++;
  m3--;
  m2--;
  long long y = m3;
  long long n = prime_count(y);
  long long p2 = 0;
  for (long long p = y + 1; p <= m2; p++)
    if (isp[p]) p2 += prime_count(lim / p) - prime_count(p) + 1;
  long long ph = phi(lim, n);
  long long res = ph + n - 1 - p2;
  return res;
}
long long calc() {
  long long ans = 0;
  for (int i = 0; i < ((int)(primes).size()); i++) {
    long long p = primes[i];
    if (p * p >= N) break;
    long long dif = prime_count(N / p) - prime_count(p);
    ans += dif;
  }
  for (long long i = 2; i * i * i <= N; i++)
    if (isp[i]) ans++;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pre();
  cin >> N;
  long long ans = calc();
  cout << ans << endl;
  return 0;
}
