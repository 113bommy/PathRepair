#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long mod = 1e9 + 7;
vector<long long> a;
long long cnt[N];
long long n;
long long ans = 0;
vector<long long> m;
long long power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2);
  ans = ans * ans;
  ans = ans % mod;
  if (b % 2 == 1) {
    ans = ans * a;
  }
  ans = ans % mod;
  return ans;
}
void d(long long n) {
  for (long long i = 1; i * i <= n; i++) {
    if (n % i != 0) continue;
    m.push_back(i);
    if (i * i == n) continue;
    m.push_back(n / i);
  }
  sort(m.begin(), m.end());
}
long long solver(long long n) {
  long long ans = 1;
  for (long long i = 1; i < m.size(); i++) {
    ans = ans * power(i, cnt[m[i - 1]] - cnt[m[i]]);
    ans = ans % mod;
  }
  ans = ans * (power(m.size(), cnt[n]) - power(m.size() - 1, cnt[n]));
  ans = ans % mod;
  return ans;
}
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long tmp;
    cin >> tmp;
    a.push_back(tmp);
    cnt[tmp]++;
  }
  for (long long i = N - 2; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
  }
  sort(a.begin(), a.end());
  for (long long i = 1; i < N; i++) {
    m.clear();
    d(i);
    ans += solver(i);
    ans = ans % mod;
  }
  cout << ans << endl;
}
