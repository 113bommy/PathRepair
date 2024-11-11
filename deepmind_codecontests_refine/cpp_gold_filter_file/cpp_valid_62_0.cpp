#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
long long powermod(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    b = b / 2;
    a = (a * a) % mod;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void Arise() {
  long long n;
  cin >> n;
  map<long long, vector<long long> > mpp1;
  for (long long i = 1; i < n; i++) {
    mpp1[i].push_back(i + 1);
  }
  for (long long i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    if (a == 0) {
      mpp1[i].push_back(n + 1);
    } else {
      mpp1[n + 1].push_back(i);
    }
  }
  for (long long i = 1; i <= n; i++) {
    vector<long long> temp = mpp1[1];
    bool f = 0;
    for (auto &val : temp) {
      if (val == n + 1) {
        f = 1;
        break;
      }
    }
    if (f) {
      bool f2 = 0;
      for (auto &val : mpp1[n + 1]) {
        if (val == i + 1) {
          f2 = 1;
          break;
        }
      }
      if (f2) {
        for (long long j = 1; j <= i; j++) {
          cout << j << " ";
        }
        cout << n + 1 << " ";
        for (long long j = i + 1; j <= n; j++) {
          cout << j << " ";
        }
        cout << "\n";
        return;
      }
    }
  }
  for (auto &val : mpp1[n + 1]) {
    if (val == 1) {
      cout << n + 1 << " ";
      for (long long i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << "\n";
      return;
    }
  }
  for (auto &val : mpp1[n]) {
    if (val == n + 1) {
      for (long long i = 1; i <= n + 1; i++) {
        cout << i << " ";
      }
      cout << "\n";
      return;
    }
  }
  cout << "-1\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    Arise();
  }
  cerr << "\n"
       << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms"
       << "\n";
}
