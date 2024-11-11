#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
vector<int> _vec[200];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a >= b) b += n;
    _vec[a].push_back(b);
  }
  for (int i = 0; i < 200; i++) {
    sort(_vec[i].begin(), _vec[i].end());
  }
  for (int k = 0; k < n; k++) {
    int total = m;
    int cnt = 0, last = 0;
    vector<int> drop[200], vec[200];
    for (int i = 0; i < 200; i++) {
      for (int j = 0; j < (int)_vec[i].size(); j++) {
        vec[i].push_back(_vec[i][j]);
      }
    }
    while (total) {
      for (int x = 0; x < n; x++) {
        int i = (x + k) % n;
        while (!drop[i].empty()) {
          total--;
          drop[i].pop_back();
          last = cnt;
        }
        if ((int)vec[i].size()) {
          int w = vec[i][(int)vec[i].size() - 1];
          if (w >= n) w -= n;
          drop[w].push_back(i);
          vec[i].pop_back();
        }
        cnt++;
      }
    }
    cout << last << " ";
  }
  cout << endl;
}
