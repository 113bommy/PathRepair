#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long int, long long int>>> graph;
vector<long long int> max_fuel;
vector<bool> visit;
const long long int N = 1e5 + 7;
const long long int inf = 1e9 + 32;
long long int n, ans;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  vector<long long int> a(n + 1);
  vector<pair<long long int, long long int>> v(m);
  for (long long int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    v[i].first = x, v[i].second = y;
    a[x]++;
    a[y]++;
  }
  if (n < 2) {
    cout << "NO";
    return 0;
  }
  bool val = false;
  long long int z = 1;
  set<long long int> ss;
  for (long long int i = 1; i <= n; i++) ss.insert(i);
  for (long long int i = 1; i <= n; i++) {
    if (a[i] != n - 1) {
      val = true;
      z = i;
      break;
    }
  }
  if (val) {
    cout << "YES"
         << "\n";
    ss.erase(z);
    for (long long int i = 0; i < m; i++) {
      if (v[i].first == z)
        ss.erase(v[i].second);
      else if (v[i].second == z)
        ss.erase(v[i].first);
    }
    long long int cur = 3;
    for (long long int i = 1; i <= n; i++) {
      if (i == *(ss.begin()))
        cout << 1 << " ";
      else if (i == z)
        cout << 2 << " ";
      else
        cout << cur++ << " ";
    }
    cout << "\n";
    cur = 3;
    for (long long int i = 1; i <= n; i++) {
      if (i == *(ss.begin()))
        cout << 1 << " ";
      else if (i == z)
        cout << 1 << " ";
      else
        cout << cur++ << " ";
    }
    cout << "\n";
  } else {
    cout << "NO";
  }
}
