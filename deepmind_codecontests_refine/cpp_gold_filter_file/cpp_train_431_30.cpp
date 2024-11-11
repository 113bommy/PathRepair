#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using V = vector<T>;
const int N = 1e5 + 5;
bool taken[3 * N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 3 * n; ++i) taken[i] = false;
    vector<pii> edges(m);
    vector<int> matching;
    for (auto &e : edges) {
      cin >> e.first >> e.second;
    }
    int id = 0;
    for (auto &e : edges) {
      ++id;
      if (taken[e.first] or taken[e.second]) continue;
      matching.push_back(id);
      taken[e.first] = taken[e.second] = true;
    }
    if ((int)matching.size() >= n) {
      cout << "Matching\n";
      for (int i = 0; i < n; ++i) {
        cout << matching[i] << ' ';
      }
    } else {
      cout << "IndSet\n";
      for (int i = 1, cnt = 0; cnt < n; ++i) {
        if (!taken[i]) {
          cout << i << ' ';
          ++cnt;
        }
      }
    }
    cout << '\n';
  }
  return 0;
}
