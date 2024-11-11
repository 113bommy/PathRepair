#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int strToInt(string& a) {
  stringstream x(a);
  int b;
  x >> b;
  return b;
}
void readI(int& a) { cin >> a; }
void readI(int& a, int& b) { cin >> a >> b; }
void readI(int& a, int& b, int& c) { cin >> a >> b >> c; }
vector<int> readVI(int n) {
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return a;
}
vector<vector<int> > readVVI(int n, int m) {
  vector<vector<int> > a(n, vector<int>(m));
  for (int i = 0; i < n; i++) a[i] = readVI(m);
  return a;
}
vector<long long> readVLL(long long n) {
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return a;
}
vector<vector<long long> > readVVLL(long long n, long long m) {
  vector<vector<long long> > a(n, vector<long long>(m));
  for (int i = 0; i < n; i++) a[i] = readVLL(m);
  return a;
}
void print(vector<int>& a) {
  for (auto el : a) {
    cout << el << ' ';
  }
  cout << '\n';
}
void print(vector<int>& a, int n) {
  int cnt = 0;
  for (auto el : a) {
    if (cnt++ == n) break;
    cout << el << ' ';
  }
  cout << '\n';
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const long long INFF = INT64_MAX;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};
void go() {
  int ans = 0, n, tmp;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    ans += tmp;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) go();
  return 0;
}
