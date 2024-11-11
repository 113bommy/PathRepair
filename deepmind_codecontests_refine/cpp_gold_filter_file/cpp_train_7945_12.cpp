#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ys[2001], xs[2001];
  vector<pair<int, int> > points;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a += 1000;
    b += 1000;
    ys[a].push_back(b);
    xs[b].push_back(a);
    points.push_back(make_pair(a, b));
  }
  for (int i = 0; i < 2001; i++) {
    sort(ys[i].begin(), ys[i].end());
    sort(xs[i].begin(), xs[i].end());
  }
  int c = 0;
  for (int i = 0; i < points.size(); i++) {
    int a = points[i].first, b = points[i].second;
    if (ys[a][0] != b) {
      if (ys[a][ys[a].size() - 1] != b) {
        if (xs[b][0] != a) {
          if (xs[b][xs[b].size() - 1] != a) {
            c++;
          }
        }
      }
    }
  }
  cout << c;
}
