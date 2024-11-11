#include <bits/stdc++.h>
using namespace std;
const int jump = 300;
const int MX = 1e5 + 5;
int p[MX], ip[MX], nxt[MX];
void overwrite(int pos, int finish, int turns) {
  if (turns == 0) {
    return;
  }
  nxt[pos] = finish;
  overwrite(ip[pos], ip[finish], turns - 1);
}
void update(int pos) {
  int finish = pos;
  for (int i = 0; i < jump; i++) {
    finish = p[finish];
  }
  overwrite(pos, finish, jump);
}
void runswap(int x, int y) {
  ip[p[x]] = y;
  ip[p[y]] = x;
  swap(p[x], p[y]);
  update(p[x]);
  update(p[y]);
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
    ip[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    runswap(i, i);
  }
  for (int j = 0; j < q; j++) {
    int v;
    cin >> v;
    if (v == 1) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      runswap(x, y);
    } else {
      int i, k;
      cin >> i >> k;
      --i;
      while (k >= jump) {
        k -= jump;
        i = nxt[i];
      }
      while (k > 0) {
        i = p[i];
        k--;
      }
      cout << i + 1 << endl;
    }
  }
  return 0;
}
