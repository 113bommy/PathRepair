#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int r = power(a, b / 2) % 1000000007;
  if (b % 2 == 0)
    return (r * r) % 1000000007;
  else
    return (((r * r) % 1000000007) * a) % 1000000007;
}
int prime[1000009];
int sumprime[1000009];
void sieve(int n) {
  prime[0] = prime[1] = 1;
  for (int i = 2; i <= sqrt(n); i++) {
    if (!prime[i]) {
      for (int j = 2 * i; j <= n; j = j + i) {
        prime[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!prime[i]) {
      sumprime[i] = sumprime[i - 1] + 1;
    } else {
      sumprime[i] = sumprime[i - 1];
    }
  }
}
bool comp(const pair<long long int, long long int> &a,
          const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
const int N = 5 * 1e5 + 9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << "1 1\n0\n";
      cout << "1 1\n0\n";
      cout << "1 1\n" << -a[0] << "\n";
      continue;
    }
    if (n == 2) {
      cout << "1 1\n" << -a[0] << "\n";
      cout << "2 2\n" << -a[1] << "\n";
      cout << "1 1\n0\n";
      continue;
    }
    if (n == 3) {
      cout << "1 1\n" << -a[0] << "\n";
      cout << "2 2\n" << -a[1] << "\n";
      cout << "3 3\n" << -a[2] << "\n";
      continue;
    }
    cout << "1 " << n << "\n";
    for (int i = 0; i < n - 1; i++) {
      long long int val = a[i] * n;
      a[i] = a[i] - val;
      val = -1 * val;
      cout << val << " ";
    }
    cout << 0 << " ";
    cout << "\n";
    cout << "1 " << n - 1 << "\n";
    for (int i = 0; i < n - 1; i++) {
      a[i] = -a[i];
      cout << a[i] << " ";
    }
    cout << "\n";
    cout << n << " " << n << "\n" << a[n - 1] << "\n";
  }
  return 0;
}
