#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
struct piii {
  int x, y, z;
  piii(int x, int y, int z) : x(x), y(y), z(z) {}
};
bool operator<(const piii &a, const piii &b) {
  return a.x != b.x ? a.x < b.x : a.y != b.y ? a.y < b.y : a.z < b.z;
}
int x, y, n, d;
int dx[200], dy[200];
map<piii, bool> mp;
bool AntonWin(int x, int y, int w) {
  if (mp.count(piii(x, y, w))) return mp[piii(x, y, w)];
  if (x * x + y * y > d * d) return mp[piii(x, y, w)] = w;
  if (w) {
    for (int i = 0; i < (int)n; ++i)
      if (AntonWin(x + dx[i], y + dy[i], 0)) {
        return mp[piii(x, y, w)] = true;
      }
    return mp[piii(x, y, w)] = false;
  } else {
    for (int i = 0; i < (int)n; ++i)
      if (!AntonWin(x + dx[i], y + dy[i], 1)) {
        return mp[piii(x, y, w)] = false;
      }
    return mp[piii(x, y, w)] = true;
  }
}
int main() {
  cin >> x >> y >> n >> d;
  for (int i = 0; i < (int)n; ++i) cin >> dx[i] >> dy[i];
  mp.clear();
  if (AntonWin(0, 0, 1))
    cout << "Anton";
  else
    cout << "Dasha";
  cout << endl;
}
