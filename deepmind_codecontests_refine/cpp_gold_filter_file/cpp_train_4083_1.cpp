#include <bits/stdc++.h>
using namespace std;
int seg[4000000];
int p[500001];
int n;
int f(int lef, int rig, int x, int y, int lev) {
  if (x > rig || lef > y) return 0;
  if (x <= lef && rig <= y) {
    return seg[lev];
  }
  int mid = (lef + rig) / 2;
  return f(lef, mid, x, y, lev * 2) + f(mid + 1, rig, x, y, lev * 2 + 1);
}
pair<int, int> a[500005];
int F(int x) { return x == p[x] ? x : p[x] = F(p[x]); }
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n == 1) {
    cout << "YES";
    return 0;
  }
  int i, j;
  int nn;
  for (nn = 1; nn < 1000000; nn *= 2)
    ;
  for (i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  long long m = 0;
  int isok = 1;
  for (i = 1; i <= n; i++) {
    m += f(1, nn, a[i].first, a[i].second, 1);
    for (j = nn + a[i].second - 1; j >= 1; j /= 2) seg[j]++;
  }
  if (m != n - 1) {
    cout << "NO";
    return 0;
  }
  for (i = 1; i <= n; i++) p[i] = i;
  set<pair<int, int>> S;
  for (i = 1; i <= n; i++) {
    queue<pair<int, int>> Q;
    for (auto k : S) {
      if (k.first > a[i].second) break;
      if (k.first > a[i].first) {
        p[F(k.second)] = F(i);
      } else
        Q.push(k);
    }
    while (!Q.empty()) {
      S.erase(Q.front());
      Q.pop();
    }
    S.insert({a[i].second, i});
  }
  for (i = 1; i <= n; i++) {
    if (F(i) != F(1)) isok = 0;
  }
  if (isok) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
