#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int a[100100];
long long b[100100];
vector<pair<pair<long long, long long>, pair<long long, long long> > >
    v[100100];
long long ans, res;
int main() {
  scanf("%d %d", &n, &m);
  int p = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    res += abs(a[i] - p);
    p = a[i];
  }
  if (m < 3) {
    printf("0\n");
    return 0;
  }
  res -= a[0];
  for (int i = 1; i <= n; i++) {
    v[i].push_back(make_pair(make_pair(0, 0), make_pair(0, 0)));
  }
  for (int i = 1; i < m - 1; i++) {
    int l = min(a[i - 1], a[i + 1]), r = max(a[i - 1], a[i + 1]),
        x = abs(a[i - 1] - a[i + 1]);
    b[a[i]] += abs(a[i - 1] - a[i]) + abs(a[i + 1] - a[i]);
    if (a[i] == l && a[i] == r) continue;
    if (a[i] != l && a[i] != r) {
      v[a[i]].push_back(make_pair(make_pair(l, 0), make_pair(0, x)));
      v[a[i]].push_back(make_pair(make_pair(r, 1), make_pair(0, x)));
      v[a[i]].push_back(make_pair(make_pair(1, 0), make_pair(-2, 2 * l + x)));
      v[a[i]].push_back(make_pair(make_pair(l, 1), make_pair(-2, 2 * l + x)));
      v[a[i]].push_back(make_pair(make_pair(r, 0), make_pair(2, -2 * r + x)));
      v[a[i]].push_back(make_pair(make_pair(n, 1), make_pair(2, -2 * r + x)));
    }
    if (a[i] == l) {
      v[a[i]].push_back(make_pair(make_pair(1, 0), make_pair(-1, r)));
      v[a[i]].push_back(make_pair(make_pair(r, 1), make_pair(-1, r)));
      v[a[i]].push_back(make_pair(make_pair(r, 0), make_pair(1, -r)));
      v[a[i]].push_back(make_pair(make_pair(n, 1), make_pair(1, -r)));
    }
    if (a[i] == r) {
      v[a[i]].push_back(make_pair(make_pair(1, 0), make_pair(-1, l)));
      v[a[i]].push_back(make_pair(make_pair(l, 1), make_pair(-1, l)));
      v[a[i]].push_back(make_pair(make_pair(l, 0), make_pair(1, -l)));
      v[a[i]].push_back(make_pair(make_pair(n, 1), make_pair(1, -l)));
    }
  }
  if (a[0] != a[1]) {
    v[a[0]].push_back(make_pair(make_pair(1, 0), make_pair(-1, a[1])));
    v[a[0]].push_back(make_pair(make_pair(a[1], 1), make_pair(-1, a[1])));
    v[a[0]].push_back(make_pair(make_pair(a[1], 0), make_pair(1, -a[1])));
    v[a[0]].push_back(make_pair(make_pair(n, 1), make_pair(1, -a[1])));
    b[a[0]] += abs(a[0] - a[1]);
  }
  if (a[m - 1] != a[m - 2]) {
    v[a[m - 1]].push_back(make_pair(make_pair(1, 0), make_pair(-1, a[m - 2])));
    v[a[m - 1]].push_back(
        make_pair(make_pair(a[m - 2], 1), make_pair(-1, a[m - 2])));
    v[a[m - 1]].push_back(
        make_pair(make_pair(a[m - 2], 0), make_pair(1, -a[m - 2])));
    v[a[m - 1]].push_back(make_pair(make_pair(n, 1), make_pair(1, -a[m - 2])));
    b[a[m - 1]] += abs(a[m - 2] - a[m - 1]);
  }
  ans = res;
  for (int i = 1; i <= n; i++) {
    if (((int)(v[i]).size()) == 1) continue;
    sort(v[i].begin(), v[i].end());
    long long al = 0, bl = 0;
    v[i][0].first.first = v[i][1].first.first;
    long long ress = res - b[i];
    for (int j = 1; j < ((int)(v[i]).size()); j++) {
      int l = v[i][j - 1].first.first, r = v[i][j].first.first;
      if (l != r) {
        ans = min(ress + min(al * r + bl, al * l + bl), ans);
      }
      if (v[i][j].first.second == 0) {
        al += v[i][j].second.first;
        bl += v[i][j].second.second;
      } else {
        al -= v[i][j].second.first;
        bl -= v[i][j].second.second;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
