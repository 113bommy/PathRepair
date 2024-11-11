#include <bits/stdc++.h>
using namespace std;
int n, k, a, b, i, j, m[5005][5005], x[5005], y[5005];
pair<int, pair<int, int> > p[100005];
int main() {
  cin >> a >> b >> k;
  while (i < k) {
    cin >> p[i].first >> p[i].second.first >> p[i].second.second;
    p[i].second.first--;
    i++;
  }
  i = 0;
  reverse(p, p + k);
  while (i < k) {
    if (p[i].first == 1 && x[p[i].second.first] == 0) {
      x[p[i].second.first] = 1;
      while (j < b) {
        if (m[p[i].second.first][j] == 0)
          m[p[i].second.first][j] = p[i].second.second;
        j++;
      }
      j = 0;
    }
    if (p[i].first == 2 && x[p[i].second.first] == 0) {
      y[p[i].second.first] = 1;
      while (j < a) {
        if (m[j][p[i].second.first] == 0)
          m[j][p[i].second.first] = p[i].second.second;
        j++;
      }
      j = 0;
    }
    i++;
  }
  i = 0;
  while (i < a) {
    while (j < b) {
      cout << m[i][j];
      if (j != b - 1) cout << " ";
      j++;
    }
    cout << endl;
    i++;
    j = 0;
  }
}
