#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  unordered_set<string> a;
  vector<pair<int, int>> v(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x = x - 1;
    y = y - 1;
    a.insert(to_string(x) + "." + to_string(y));
    a.insert(to_string(y) + "." + to_string(x));
    v[i] = {x, y};
  }
  int sum = 0;
  for (int i = 1; i <= n / 2; i++) {
    if (n % i != 0) continue;
    bool ok = true;
    for (int j = 0; j < m; j++) {
      string key = to_string((v[j].first + i) % n) + "." +
                   to_string((v[j].second + i) % n);
      if (a.find(key) == a.end()) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
