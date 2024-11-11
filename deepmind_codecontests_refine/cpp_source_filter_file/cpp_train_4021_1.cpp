#include <bits/stdc++.h>
using namespace std;
template <class T>
void DBGpair(T a, string s = "") {
  cerr << s << (s == "" ? "" : ": ") << a.first << ", " << a.second << "\n";
}
template <class T>
void DBGvec(vector<T> a) {
  for (T i : a) cerr << i << " ";
  cerr << "\n";
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7;
const long long INF = 1e9;
void setIO(string filename) {
  if (fopen((filename + ".in").c_str(), "r")) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort((a).begin(), (a).end());
  set<long long> v;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      v.insert(a[j] - a[i]);
    }
  }
  int j = 1;
  bitset<1000001> bad;
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    while (bad[j]) j++;
    b[i] = j;
    for (auto k : v) bad[k + j] = 1;
    j++;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) solve();
}
