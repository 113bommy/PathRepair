#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
using namespace std;
void vok() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return ((a * b) / gcd(a, b));
}
vector<long long int> pp;
void gen() {
  vector<bool> prime(33000, true);
  prime[0] = prime[1] = false;
  for (int p = 0; p * p <= 33000; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= 33000; i += p) prime[i] = false;
    }
  }
  for (int i = 0; i < 33000; i++)
    if (prime[i]) pp.push_back(i);
}
long long int find(vector<int> &A, int n) {}
void fill(string &str, int a, int b) {
  for (int i = 0; i < a; i++) str += 'R';
  for (int i = 0; i < b; i++) str += 'U';
}
void solve() {
  long long int n, m, x, y, a, b, k;
  a = b = x = y = k = 0;
  long long int ans = 0, res = 0;
  cin >> n;
  string str;
  vector<pair<int, int> > A;
  for (int i = 0; i < n; i++) {
    cin >> a;
    cin >> b;
    A.push_back({a, b});
    ;
  }
  sort(A.begin(), A.end());
  string s1 = "";
  fill(s1, A[0].first, A[0].second);
  for (int i = 1; i < n; i++) {
    if (A[i].first >= A[i - 1].first and A[i].second >= A[i - 1].second) {
      fill(s1, A[i].first - A[i - 1].first, A[i].second - A[i - 1].second);
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  cout << s1 << endl;
}
int main() {
  vok();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
