#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> f(n);
    vector<int> v[100005];
    vector<int> b(n);
    vector<int> a(n);
    vector<int> used(100005, 0);
    for (int i = 0; i < n; i++) {
      cin >> f[i];
      v[f[i]].push_back(i + 1);
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    int sizeA = 0;
    int state = -1;
    for (int i = 0; i < m; i++) {
      if (v[b[i]].size()) {
        a[sizeA++] = v[b[i]][0];
        used[b[i]]++;
      } else {
        sizeA = 0;
        break;
      }
    }
    if (sizeA < m) {
      cout << "Impossible" << endl;
      continue;
    }
    for (int i = 0; i < 100005 && state == -1; i++) {
      if (used[i] > 1 && v[i].size() > 1) {
        state = 1;
      }
    }
    if (state == 1 || sizeA > m) {
      cout << "Ambiguity" << endl;
    } else {
      cout << "Possible" << endl;
      for (int i = 0; i < m; i++) {
        if (i) cout << " ";
        cout << a[i];
      }
      cout << endl;
    }
  }
}
