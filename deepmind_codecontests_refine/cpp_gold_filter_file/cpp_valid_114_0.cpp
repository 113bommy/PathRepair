#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long int exp(long long int x, long long int y) {
  if (y == 0) return 1;
  if (x == 0 || x == 1) return x;
  long long int p = exp(x, y / 2);
  p = (p * p);
  if (y % 2) p = (x * p);
  return p;
}
bool check_prime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
const long long int max_size = 1e7 + 5;
bool prime[max_size];
void prime_seive(long long int n) {
  memset(prime, true, sizeof(prime));
  for (long long int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long int j = i * i; j <= n; j += i) prime[j] = false;
    }
  }
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  for (long long int z = 1; z <= t; z++) {
    solve();
  }
  return 0;
}
void solve() {
  long long int n;
  cin >> n;
  vector<vector<long long int> > A(n);
  for (long long int i = 0; i < n; i++) {
    long long int cnt;
    cin >> cnt;
    for (long long int j = 0; j < cnt; j++) {
      long long int d;
      cin >> d;
      A[i].push_back(d);
    }
  }
  long long int m;
  cin >> m;
  vector<vector<long long int> > B(m);
  set<vector<long long int> > s;
  for (long long int i = 0; i < m; i++) {
    for (long long int j = 0; j < n; j++) {
      long long int d;
      cin >> d;
      B[i].push_back(d - 1);
    }
    s.insert(B[i]);
  }
  priority_queue<pair<long long int, vector<long long int> > > q;
  long long int sum = 0;
  vector<long long int> pp;
  for (long long int i = 0; i < n; i++) {
    sum += A[i].back();
    pp.push_back(A[i].size() - 1);
  }
  q.push({sum, pp});
  vector<long long int> ans;
  while (!q.empty()) {
    pair<long long int, vector<long long int> > p = q.top();
    q.pop();
    long long int add = p.first;
    vector<long long int> pos = p.second;
    if (s.find(p.second) == s.end()) {
      ans = p.second;
      break;
    }
    for (long long int i = 0; i < n; i++) {
      if (pos[i] > 0) {
        add -= A[i][pos[i]];
        add += A[i][pos[i] - 1];
        pos[i]--;
        q.push({add, pos});
        pos[i]++;
        add += A[i][pos[i]];
        add -= A[i][pos[i] - 1];
      }
      if (pos[i] < A[i].size() - 1) {
        break;
      }
    }
  }
  for (long long int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << "\n";
  return;
}
