#include <bits/stdc++.h>
using namespace std;
int used[100000];
int n, m;
vector<int> v[100000], groups[2];
void f(int point, int group) {
  used[point] = group;
  groups[group - 1].push_back(point);
  for (int i = 0; i < v[point].size(); i++) {
    if (used[v[point][i]]) {
      if (used[v[point][i]] == group) {
        cout << -1;
        exit(0);
      }
    } else
      f(v[point][i], 3 - group);
  }
}
int main() {
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    v[x - 1].push_back(y - 1);
    v[y - 1].push_back(x - 1);
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) f(i, 1);
  }
  for (int j = 0; j < 2; j++) {
    cout << groups[j].size() << endl;
    for (int i = 0; i < groups[j].size(); i++) cout << groups[j][i] + 1 << " ";
    cout << endl;
  }
}
