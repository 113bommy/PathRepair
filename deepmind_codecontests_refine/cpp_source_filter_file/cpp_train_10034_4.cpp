#include <bits/stdc++.h>
using namespace std;
bool can[10];
int ip[20];
int up(int x) {
  if (x == 0) return 0;
  if (x == 1) return 10;
  if (x == 2) return 100;
  if (x == 3) return 256;
}
int l, len;
bool next_c() {
  for (int(i) = (l)-1; (i) >= (0); --(i))
    if (ip[i] != 9) {
      ++ip[i];
      for (int(j) = (i + 1); j < (l); ++(j)) ip[j] = 0;
      return true;
    }
  return false;
}
vector<vector<int>> ans;
void ok(int n1, int n2, int n3, int n4) {
  vector<int> ipful(ip, ip + l), v;
  if (len & 1)
    for (int(i) = (l - 1) - 1; (i) >= (0); --(i)) ipful.push_back(ip[i]);
  else
    for (int(i) = (l)-1; (i) >= (0); --(i)) ipful.push_back(ip[i]);
  int x = 0;
  for (int(i) = (0); i < (n1); ++(i)) x = x * 10 + ipful[i];
  if (x < up(n1 - 1) || x > up(n1)) return;
  v.push_back(x);
  x = 0;
  for (int(i) = (n1); i < (n1 + n2); ++(i)) x = x * 10 + ipful[i];
  if (x < up(n2 - 1) || x > up(n2)) return;
  v.push_back(x);
  x = 0;
  for (int(i) = (n1 + n2); i < (n1 + n2 + n3); ++(i)) x = x * 10 + ipful[i];
  if (x < up(n3 - 1) || x > up(n3)) return;
  v.push_back(x);
  x = 0;
  for (int(i) = (n1 + n2 + n3); i < (n1 + n2 + n3 + n4); ++(i))
    x = x * 10 + ipful[i];
  if (x < up(n4 - 1) || x > up(n4)) return;
  v.push_back(x);
  ans.push_back(v);
}
int main() {
  int n, a;
  cin >> n;
  if (n > 6) {
    cout << 0;
    return 0;
  }
  for (int(i) = (0); i < (n); ++(i)) {
    cin >> a;
    can[a] = true;
  }
  for (int(n1) = (1); n1 < (4); ++(n1))
    for (int(n2) = (1); n2 < (4); ++(n2))
      for (int(n3) = (1); n3 < (4); ++(n3))
        for (int(n4) = (1); n4 < (4); ++(n4)) {
          len = n1 + n2 + n3 + n4;
          l = (len + 1) / 2;
          memset(ip, 0, sizeof(ip));
          do {
            int need = n;
            bool done[10] = {0};
            for (int(i) = (0); i < (l); ++(i))
              if (!can[ip[i]])
                goto nxt;
              else if (!done[ip[i]]) {
                done[ip[i]] = true;
                --need;
              }
            if (need) goto nxt;
            ok(n1, n2, n3, n4);
          nxt:;
          } while (next_c());
        }
  cout << ans.size() << '\n';
  for (int(i) = (0); i < (ans.size()); ++(i))
    for (int(j) = (0); j < (4); ++(j))
      cout << ans[i][j] << (j == 3 ? '\n' : '.');
  return 0;
}
