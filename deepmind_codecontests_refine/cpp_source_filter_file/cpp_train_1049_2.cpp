#include <bits/stdc++.h>
using namespace std;
int cur;
vector<pair<int, int>> e;
int n, d, k;
void add(int i, int dist, int left) {
  if (dist == d) return;
  for (int j = 0; j < left && cur + 1 < n; j++) {
    e.push_back({i, ++cur});
    add(cur, dist + 1, k - 1);
  }
}
int main() {
  cin >> n >> d >> k;
  if (k == 1 && d > 2) {
    cout << "NO\n";
    return 0;
  }
  ++d;
  for (int i = 0; i < d - 1; i++) {
    e.push_back({i, i + 1});
  }
  int s = 0, t = d - 1;
  cur = d - 1;
  for (int i = 1; i < t; i++) {
    add(i, max(i - s + 1, t - i + 1), k - 2);
  }
  if (cur + 1 == n) {
    cout << "YES\n";
    for (auto v : e) {
      cout << v.first + 1 << ' ' << v.second + 1 << '\n';
    }
  } else {
    cout << "NO\n";
  }
}
