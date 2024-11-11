#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int par[MAXN];
int hate[MAXN];
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void join(int x, int y) {
  int px = find(x);
  int py = find(y);
  if (px == py) return;
  par[px] = py;
  if (hate[px] == -1) hate[px] = hate[py];
}
unordered_map<string, int> mp;
int main() {
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < (n); ++i) {
    string s;
    cin >> s;
    int idx = (int)((mp).size());
    mp[s] = idx;
    hate[i] = -1;
    par[i] = i;
  }
  for (int i = 0; i < (m); ++i) {
    int t;
    string s1, s2;
    cin >> t >> s1 >> s2;
    int x = mp[s1];
    int y = mp[s2];
    int px = find(x);
    int py = find(y);
    if (t == 1) {
      if (hate[px] != -1 && find(hate[px]) == find(py)) {
        cout << "NO" << endl;
        continue;
      }
      if (hate[px] == -1 && hate[py] == -1) {
        join(px, py);
      } else if (hate[px] == -1) {
        join(px, py);
      } else if (hate[py] == -1) {
        join(px, py);
      } else {
        join(px, py);
        join(hate[px], hate[py]);
      }
    } else {
      if (px == py) {
        cout << "NO" << endl;
        continue;
      }
      if (hate[px] == -1 && hate[py] == -1) {
        hate[px] = y;
        hate[py] = x;
      } else if (hate[px] == -1) {
        join(px, hate[py]);
      } else if (hate[py] == -1) {
        join(py, hate[px]);
      } else {
        join(hate[px], py);
        join(px, hate[py]);
      }
    }
    cout << "YES" << endl;
  }
  while (q--) {
    string s1, s2;
    cin >> s1 >> s2;
    int x = mp[s1];
    int y = mp[s2];
    int px = find(x);
    int py = find(y);
    if (px == py)
      cout << 1 << endl;
    else if (hate[px] != -1 && find(hate[px]) == py)
      cout << 2 << endl;
    else
      cout << 3 << endl;
  }
  return 0;
}
