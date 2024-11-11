#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<long long int> a, vector<long long int> b) {
  return a[0] > b[0];
}
bool sortfirst(pair<long long int, char> a, pair<long long int, char> b) {
  return a.first > b.first;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
bool isPowerOfTwo(long long int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
double sumOfGP(double a, double r, long long int n) {
  double sum = 0;
  for (long long int i = 0; i < n; i++) {
    sum = sum + a;
    a = a * r;
  }
  return sum;
}
bool check(string s) {
  stack<char> st;
  for (long long int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      st.push('(');
    else {
      if (st.empty()) {
        return false;
      } else
        st.pop();
    }
  }
  if (st.empty())
    return true;
  else
    return false;
}
long long int mod = 1e9 + 7;
bool iszero(string a) {
  for (long long int i = 0; i < a.length(); i++) {
    if (a[i] == '1') return false;
  }
  return true;
}
long long int fac(long long int n) {
  if (n <= 0) return 1;
  return (n * fac(n - 1)) % mod;
}
long long int calSumGP(long long int a, long long int r, long long int n) {
  long long int sum = 0, temp = a % mod;
  for (long long int i = 1; i < n; i++) {
    sum = sum + temp;
    temp = (temp * r) % mod;
  }
  return sum % mod;
}
bool checksort(long long int a[], long long int n) {
  for (long long int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) return false;
  }
  return true;
}
long long int mxN = 1e6 + 5;
bool checksq(long long int n) {
  long long int t = sqrt(n);
  if (t * t == n) return true;
  return false;
}
long long int rec(long long int a[], long long int n, long long int i,
                  long long int sum) {
  long long int mx = 0;
  sum += a[i];
  if (i + 1 < n && sum >= 0) {
    for (long long int k = i + 1; k < n; k++) {
      if (k < n && sum + a[k] >= 0) mx = max(mx, (1 + rec(a, n, k, sum)));
    }
  }
  return mx;
}
bool checkPrime(long long int n) {
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
long long int countDigit(long long int n) { return floor(log10(n) + 1); }
const long long int size = 4e5 + 7;
vector<long long int> adj[size];
bool vis[size];
void dfs(int node) {
  vis[node] = true;
  for (auto it : adj[node]) {
    if (!vis[it]) dfs(it);
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int>> vp;
  while (n--) {
    long long int x, y;
    cin >> x >> y;
    vp.push_back({x, y});
  }
  if (vp.size() == 1) {
    cout << 1;
    return;
  }
  long long int cnt = 0;
  for (long long int i = 1; i + 1 < vp.size(); i++) {
    if ((vp[i].first - vp[i].second) > vp[i - 1].first) {
      cnt++;
    } else if ((vp[i].first + vp[i].second) < vp[i + 1].first) {
      cnt++;
      vp[i].first += vp[i].second;
    }
  }
  if (vp.size() >= 2) cnt += 2;
  cout << cnt;
}
int main() {
  solve();
  return 0;
}
