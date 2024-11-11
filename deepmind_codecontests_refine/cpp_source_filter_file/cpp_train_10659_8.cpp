#include <bits/stdc++.h>
using namespace std;
template <class T>
void PV(T a, T b) {
  for (T i = a; i < b; ++i) cout << *i << " ";
  cout << endl;
}
template <class T>
void chmin(T &t, T f) {
  if (t > f) t = f;
}
template <class T>
void chmax(T &t, T f) {
  if (t < f) t = f;
}
int n, x;
int d[1010];
int father[10000], rk[10000];
int FindSet(int x) {
  if (father[x] != x) father[x] = FindSet(father[x]);
  return father[x];
}
void Union(int x, int y) {
  x = FindSet(x), y = FindSet(y);
  if (x == y) return;
  if (rk[x] > rk[y]) {
    father[y] = x;
    rk[x] += rk[y];
  } else {
    father[x] = y;
    rk[y] += rk[x];
  }
}
int v[10010];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> x;
  for (int i = 1; i <= n; i++) father[i] = i, rk[i] = 1;
  for (int i = 1; i <= n; i++) cin >> d[i];
  int c = 1;
  int t = x;
  while (d[t] > 0) {
    c++;
    t = d[t];
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] > 0) Union(i, d[i]);
  }
  vector<int> p;
  for (int i = 1; i <= n; i++)
    if (father[i] == i && FindSet(i) != FindSet(2)) p.push_back(rk[i]);
  int m = p.size();
  v[0] = 1;
  for (int j = 0; j < m; j++)
    for (int i = 1000; i >= 0; i--)
      if (v[i]) v[i + p[j]] = 1;
  for (int i = 0; i < 1010; i++) {
    if (v[i]) cout << c + i << endl;
  }
  return 0;
}
