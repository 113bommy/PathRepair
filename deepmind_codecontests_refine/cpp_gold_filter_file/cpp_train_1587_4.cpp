#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long N = (long long)(1e6 + 5);
long long n;
long long p[N];
bool seen[N];
long long ans[N];
vector<long long> primes;
void work() {
  cin >> n;
  long long prime_cnt = 1;
  for (long long i = 1; i <= n; i++) p[i] = 1;
  for (long long i = 2; i <= n; i++) {
    if (p[i] > 1) continue;
    prime_cnt += 1;
    for (long long j = 2 * i; j <= n; j += i) {
      if (p[j] > 1) continue;
      p[j] = i;
    }
    primes.push_back(i);
  }
  for (long long i = 0; i < prime_cnt; i++) ans[i] = 1;
  long long cur = 2, idx = prime_cnt;
  while (idx < n) {
    long long smallest_prime = (p[cur] == 1) ? cur : p[cur];
    for (auto pp : primes) {
      if (pp > smallest_prime || pp * cur > n) {
        break;
      }
      ans[idx++] = cur;
    }
    cur += 1;
  }
  for (long long i = 1; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  for (long long i = 0; i < t; i++) {
    work();
  }
}
