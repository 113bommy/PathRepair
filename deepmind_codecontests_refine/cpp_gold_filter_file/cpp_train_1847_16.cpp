#include <bits/stdc++.h>
using namespace std;
int k, n;
const int N = 200005;
vector<int> a[N];
vector<int> s;
vector<pair<int, int> > b;
bool cmp(pair<int, int> x, pair<int, int> y) {
  return a[x.first][x.second] < a[y.first][y.second];
}
int main() {
  cin >> k;
  int u, r;
  for (int i = 0; i < k; i++) {
    cin >> n;
    r = 0;
    for (int j = 0; j < n; j++) {
      cin >> u;
      a[i].push_back(u);
      r += u;
    }
    s.push_back(r);
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      a[i][j] = s[i] - a[i][j];
      b.push_back(make_pair(i, j));
    }
  }
  sort(b.begin(), b.end(), cmp);
  for (int i = 1; i < b.size(); i++) {
    pair<int, int> x = b[i - 1];
    pair<int, int> y = b[i];
    if (x.first == y.first) continue;
    if (a[x.first][x.second] == a[y.first][y.second]) {
      cout << "YES" << endl;
      cout << x.first + 1 << " " << x.second + 1 << endl;
      cout << y.first + 1 << " " << y.second + 1 << endl;
      return 0;
    }
  }
  cout << "NO";
}
