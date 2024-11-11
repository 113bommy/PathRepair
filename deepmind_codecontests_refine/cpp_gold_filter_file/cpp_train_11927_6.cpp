#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> ft;
long long n, m, k;
struct quer {
  long long x1, y1, x2, y2;
};
void add(long long x, long long y, long long val) {
  for (int i = x; i <= n; i += i & -i) {
    for (int j = y; j <= m; j += j & -j) {
      ft[i][j] += val;
    }
  }
}
long long sum(long long x, long long y) {
  long long ret = 0;
  for (int i = x; i > 0; i -= i & -i) {
    for (int j = y; j > 0; j -= j & -j) {
      ret += ft[i][j];
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  ft.assign(n + 1, vector<long long>(m + 1, 0));
  vector<vector<pair<long long, pair<long long, long long>>>> garlands(k + 1);
  for (int i = 1; i < k + 1; i++) {
    long long siz;
    cin >> siz;
    pair<long long, pair<long long, long long>> temp;
    while (siz--) {
      cin >> temp.second.first >> temp.second.second >> temp.first;
      garlands[i].push_back(temp);
    }
  }
  vector<long long> tc;
  vector<quer> rect;
  long long q;
  cin >> q;
  tc.resize(q + 1, 0);
  for (int i = 1; i < q + 1; i++) {
    string s;
    cin >> s;
    if (s == "ASK") {
      quer temp;
      cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
      rect.push_back(temp);
    } else
      cin >> tc[i];
  }
  vector<vector<long long>> rvg(rect.size() + 1, vector<long long>(k + 2, 0));
  for (int i = 1; i < k + 1; i++) {
    for (auto j : garlands[i]) add(j.second.first, j.second.second, j.first);
    for (int j = 0; j < rect.size(); j++) {
      rvg[j][i] =
          sum(rect[j].x2, rect[j].y2) - sum(rect[j].x1 - 1, rect[j].y2) -
          sum(rect[j].x2, rect[j].y1 - 1) + sum(rect[j].x1 - 1, rect[j].y1 - 1);
    }
    for (auto j : garlands[i]) add(j.second.first, j.second.second, -j.first);
  }
  vector<long long> isOn(k + 1, 1);
  long long ind = 0;
  for (int i = 1; i < q + 1; i++) {
    if (tc[i])
      isOn[tc[i]] ^= 1;
    else {
      long long ans = 0;
      for (int j = 1; j < k + 1; j++)
        if (isOn[j]) ans += rvg[ind][j];
      ind++;
      cout << ans << '\n';
    }
  }
  return 0;
}
