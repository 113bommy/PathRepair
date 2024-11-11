#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(10);
  ;
  int n;
  cin >> n;
  vector<int> deg(n);
  int ones = 0;
  vector<int> others, ops;
  long long total = 0;
  for (int i = 0; i < (int)n; i++) {
    cin >> deg[i];
    if (deg[i] == 1) {
      ones++;
      ops.push_back(i);
    } else {
      total += deg[i];
      others.push_back(i);
    }
  }
  if (total - (n - ones - 1) * 2 < ones) return cout << "NO\n", 0;
  vector<pair<int, int>> edges;
  if (others.size() == 0 && ops.size() == 2) {
    cout << "YES 1\n";
    cout << "1\n";
    cout << ops[0] + 1 << " " << ops[1] + 1 << "\n";
    return 0;
  }
  for (int i = 1; i < (int)others.size(); i++) {
    edges.push_back({others[i - 1], others[i]});
  }
  int opptr = 0;
  if (others.size() == 1) {
    for (int i = 0; i < (int)ops.size(); i++)
      edges.push_back({ops[i], others[0]});
  } else {
    if (opptr < (int)ops.size()) edges.push_back({ops[opptr++], others[0]});
    if (opptr < (int)ops.size()) edges.push_back({ops[opptr++], others.back()});
    for (int i = 0; i < (int)deg[others[0]] - 2; i++) {
      if (opptr >= (int)ops.size()) break;
      edges.push_back({ops[opptr++], others[0]});
    }
    for (int i = 0; i < (int)deg[others.back()] - 2; i++) {
      if (opptr >= (int)ops.size()) break;
      edges.push_back({ops[opptr++], others.back()});
    }
  }
  for (int i = 1; i < (int)others.size() - 1; i++) {
    int av = deg[others[i]] - 2;
    while (opptr < (int)ops.size() && av > 0) {
      edges.push_back({others[i], ops[opptr++]});
      av--;
    }
  }
  cout << "YES " << (others.size() - 1 + (ops.size() > 0) + (ops.size() > 1))
       << "\n";
  cout << edges.size() << "\n";
  for (int i = 0; i < (int)edges.size(); i++)
    cout << (edges[i].first + 1) << " " << edges[i].second + 1 << "\n";
}
