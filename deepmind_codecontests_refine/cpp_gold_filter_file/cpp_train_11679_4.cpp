#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long double pi = acosl(-1);
const int inf = 1e9;
const int nmax = 1e6 + 5;
const int MAXLG = log2(nmax) + 1;
vector<int> g[nmax];
int whodis[nmax];
int cnt[nmax];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    v.push_back({x, i});
    cnt[x]++;
  }
  sort(v.rbegin(), v.rend());
  int mx = v[0].first;
  int rightmax = mx;
  int curL = 1;
  for (pair<int, int> x : v) {
    while (whodis[curL]) curL++;
    whodis[curL] = x.second * 2;
    if (whodis[curL + x.first]) {
      g[curL + x.first - 1].push_back(x.second * 2 - 1);
    } else {
      if (curL + x.first - rightmax <= 1) {
        whodis[curL + x.first] = x.second * 2 - 1;
        rightmax = max(curL + x.first, rightmax);
      } else {
        g[curL - x.first + 1].push_back(x.second * 2 - 1);
        rightmax = max(rightmax, curL);
      }
    }
  }
  for (int i = 1; i < rightmax; i++) {
    cout << whodis[i] << " " << whodis[i + 1] << "\n";
  }
  for (int i = 1; i <= rightmax; i++) {
    for (int x : g[i]) cout << whodis[i] << " " << x << "\n";
  }
}
