#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long mod = 1e9 + 7;
const long long N = 1e5 + 5, K = 105;
const int si = (1 << 20);
const long long add = 1e4;
const long long oo = (long long)1e18;
const long long M = 100000 + 5;
const double INFdb = 1e10;
int n;
int d[N];
pair<int, int> p[N];
vector<int> v[N * 2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    p[i] = make_pair(d[i], i);
  }
  sort(p + 1, p + 1 + n);
  reverse(p + 1, p + 1 + n);
  for (int i = 1; i <= n; ++i) {
    v[i].push_back(p[i].second * 2 - 1);
  }
  for (int i = 1; i <= n; ++i) {
    v[i + p[i].first].push_back(p[i].second * 2);
  }
  for (int i = 2; i < N * 2; ++i) {
    for (int x : v[i]) {
      cout << x << " " << v[i - 1].back() << "\n";
    }
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
