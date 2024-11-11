#include <bits/stdc++.h>
using namespace std;
int n, m;
struct MAP {
  map<int, int> mp;
  vector<int> v;
  void init() {
    mp.clear();
    v.clear();
  }
  void add(int x) { mp[x]; }
  void build() {
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
      it->second = v.size();
      v.push_back(it->first);
    }
  }
  int size() { return v.size(); };
  int operator[](int i) const { return mp.find(i)->second; }
  int operator()(int i) const { return v[i]; };
} mx, my;
int x[2100], y[2100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char dz[5] = "ULDR";
int find_it(char ch) {
  for (int i = 0; i < 4; i++)
    if (ch == dz[i]) return i;
}
int op[2100], len[2100];
bool a[2100][2100];
int f[2100][2100];
int main() {
  cin >> n;
  mx.init(), my.init();
  mx.add(-1000000007), my.add(-1000000007);
  mx.add(1000000007), my.add(1000000007);
  int sx = 0, sy = 0, tx, ty;
  for (int k = 0; k < n; k++) {
    scanf(" %c %d", op + k, len + k);
    tx = sx + dx[find_it(op[k])] * len[k];
    ty = sy + dy[find_it(op[k])] * len[k];
    mx.add(min(sx, tx));
    mx.add(max(sx, tx) + 1);
    my.add(min(sy, ty));
    my.add(max(sy, ty) + 1);
    sx = tx, sy = ty;
  }
  mx.build();
  my.build();
  for (int i = 0; i < mx.size(); ++i)
    for (int j = 0; j < my.size(); ++j) a[i][j] = 0, f[i][j] = 0;
  sx = 0, sy = 0;
  for (int k = 0; k < n; k++) {
    tx = sx + dx[find_it(op[k])] * len[k];
    ty = sy + dy[find_it(op[k])] * len[k];
    for (int i = mx[min(sx, tx)]; i < mx[max(sx, tx) + 1]; ++i)
      for (int j = my[min(sy, ty)]; j < my[max(sy, ty) + 1]; ++j) a[i][j] = 1;
    sx = tx, sy = ty;
  }
  queue<pair<int, int> > q;
  f[0][0] = 1;
  q.push(make_pair(0, 0));
  while (q.size()) {
    int vx = q.front().first, vy = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int vex = vx + dx[i], vey = vy + dy[i];
      if (vex < 0 || vex > mx.size() || vey < 0 || vey > my.size()) continue;
      if ((!a[vex][vey]) && (!f[vex][vey])) {
        f[vex][vey] = 1;
        q.push(make_pair(vex, vey));
      }
    }
  }
  long long ans = 0LL;
  for (int i = 0; i < mx.size() - 1; ++i)
    for (int j = 0; j < my.size() - 1; ++j)
      if (!f[i][j]) {
        ans += (long long)(mx(i + 1) - mx(i)) * (long long)(my(j + 1) - my(j));
      }
  cout << ans << endl;
  return 0;
}
