#include <bits/stdc++.h>
using namespace std;
long long fx[4] = {1, -1, 0, 0};
long long fy[4] = {0, 0, 1, -1};
vector<long long> ans;
pair<long long, long long> pt[200003];
long long p[200003];
bool prime[200003 + 10];
long long pw(long long a, long long b) {
  long long ans = 1;
  for (long long i = 1; i <= b; ++i) ans = (ans * a);
  return ans;
}
void SieveOfEratosthenes() {
  long long n = 500;
  memset(prime, true, sizeof(prime));
  for (int p = 2; p <= n; p++) {
    if (prime[p] == true) {
      ans.push_back(p);
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  {
    SieveOfEratosthenes();
    memset(pt, -1, sizeof(pt));
    memset(p, 0, sizeof(p));
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      long long x, c;
      cin >> x;
      for (auto i : ans) {
        c = 0;
        while (x % i == 0) {
          x /= i;
          c++;
        }
        if (c < pt[i].first || pt[i].first == -1) {
          pt[i].second = pt[i].first;
          pt[i].first = c;
        } else if (c < pt[i].second || pt[i].second == -1)
          pt[i].second = c;
      }
      p[x]++;
    }
    long long ans = 1;
    for (long long i = 2; i < 200003 - 1; i++) {
      if (i <= 500) {
        if (pt[i].second != -1) ans *= pw(i, pt[i].second);
      } else {
        if (p[i] >= n - 1) ans *= i;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
