#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool compare(const pair<long long, long long>& i,
             const pair<long long, long long>& j) {
  return i.second < j.second;
}
long long fact[N];
vector<bool> is_prime(100000, true);
vector<int> prime;
void pre() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = i * fact[i - 1];
    fact[i] %= mod;
  }
}
long long modexp(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return r % mod;
}
long long modinv(long long x) { return modexp(x, mod - 2); }
long long ncr(long long n, long long r) {
  if (n < r) return 0;
  long long ans =
      (fact[n] % mod * modinv(fact[r]) % mod * modinv(fact[n - r]) % mod) % mod;
  return ans;
}
long long exp(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * x);
    x = (x * x);
    n >>= 1;
  }
  return r;
}
void solve() {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> A(n);
  vector<int> ans;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum += A[i];
    m[A[i]]++;
  }
  sort(A.begin(), A.end());
  if (m[0] == 0) {
    cout << -1 << "\n";
    return;
  }
  int flag = 0;
  if (sum % 3 == 0) {
    for (int i = 0; i < 10; i++) {
      while (m[i]--) {
        ans.push_back(i);
      }
    }
  } else if (sum % 3 == 1) {
    for (int i = 0; i < n; i++) {
      if (A[i] % 3 == 1) {
        m[A[i]]--;
        flag = 1;
        break;
      }
    }
    int cnt = 0;
    if (flag == 0) {
      for (int i = 0; i < n; i++) {
        if (A[i] % 3 == 2) {
          m[A[i]]--;
          cnt++;
          if (cnt >= 2) {
            flag = 1;
            break;
          }
        }
      }
    }
    if (flag == 0) {
      cout << 0 << "\n";
      return;
    }
    for (int i = 0; i < 10; i++) {
      while (m[i]--) {
        ans.push_back(i);
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (A[i] % 3 == 2) {
        m[A[i]]--;
        flag = 1;
        break;
      }
    }
    int cnt = 0;
    if (flag == 0) {
      for (int i = 0; i < n; i++) {
        if (A[i] % 3 == 1) {
          m[A[i]]--;
          cnt++;
          if (cnt >= 2) {
            flag = 1;
            break;
          }
        }
      }
    }
    if (flag == 0) {
      cout << 0 << "\n";
      return;
    }
    for (int i = 0; i < 10; i++) {
      while (m[i]--) {
        ans.push_back(i);
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<int>());
  if (ans[0] == 0) {
    cout << 0 << "\n";
    return;
  }
  for (auto x : ans) cout << x;
  cout << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
