#include <bits/stdc++.h>
using namespace std;
long long int mod_pow(long long int x, int n) {
  if (n == 0) return 1;
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % 1000000007;
    x = x * x % 1000000007;
    n >>= 1;
  }
  return res;
}
vector<long long int> allDivisors(long long int n) {
  vector<long long int> v;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        v.emplace_back(i);
      else {
        v.emplace_back(i);
        v.emplace_back(n / i);
      }
    }
  }
  return v;
}
bool isPalin(string s) {
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) {
      return false;
    }
  }
  return true;
}
vector<int> z_algo(string s) {
  int n = s.size();
  int l = 0, r = 0;
  vector<int> z(n);
  for (long long int i = 1; i < n; i++) {
    if (i > r) {
      l = r = i;
      while (r < n && s[r] == s[r - l]) {
        r++;
      }
      z[i] = r - l;
      r--;
    } else {
      long long int index = i - l;
      if (i + z[index] <= r)
        z[i] = z[index];
      else {
        l = i;
        while (r < n && s[r] == s[r - l]) {
          r++;
        }
        z[i] = r - l;
        r--;
      }
    }
  }
  return z;
}
vector<int> z_match(string str, string pat) {
  string total = pat + "$" + str;
  vector<int> z = z_algo(total);
  vector<int> ans;
  for (int i = 0; i < z.size(); i++) {
    if (z[i] == pat.size()) {
      ans.emplace_back(i - 1 - pat.size());
    }
  }
  return ans;
}
vector<int> kmp(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
vector<int> kmp_match(string str, string pat) {
  string total = pat + "$" + str;
  int n = total.size();
  vector<int> ans = kmp(total);
  vector<int> res;
  for (int i = pat.size() + 1; i < n; i++) {
    if (ans[i] == pat.size()) {
      res.emplace_back(i - 2 * pat.size());
    }
  }
  return res;
}
bool isPrime(long long int n) {
  int skip = 0;
  if (n < 2)
    return false;
  else if (n == 2)
    return true;
  long long int limit = sqrt(n);
  if (n % 2 == 0) return false;
  for (int j = 3; j <= limit; j += 2) {
    if (n % j == 0) return false;
  }
  return true;
}
long long int fact(long long int n) {
  if (n == 1)
    return 1;
  else
    return (n % 1000000007 * fact(n - 1) % 1000000007) % 1000000007;
}
long long int kadane(vector<long long int> &a, int n) {
  long long int curr = a[0];
  long long int ans = a[0];
  for (int i = 1; i <= n - 1; i++) {
    curr += a[i % n];
    ans = max(ans, curr);
    curr = max(curr, 0LL);
  }
  return ans;
}
bool comp(const pair<long long int, long long int> &a,
          const pair<long long int, long long int> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  } else {
    return a.second < b.second;
  }
}
void read(vector<int> &a, int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
bool fine = 0;
void solve() {
  long long int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) ans += abs(a[i]);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  if (fine) {
    int t;
    cin >> t;
    while (t--) {
      solve();
    }
  } else
    solve();
  return 0;
}
