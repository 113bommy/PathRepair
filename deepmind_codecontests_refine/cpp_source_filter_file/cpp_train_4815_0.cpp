#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000000;
int bit[MAXN];
int n, q;
int lowbit(int x) { return x & (-x); }
void add(int x, int val) {
  for (; x <= MAXN; x += lowbit(x)) {
    bit[x] += val;
  }
}
void rm(int x) {
  int s = 0, c = 0;
  for (int i = 19; i > -1; --i) {
    s += (1 << i);
    if (s > MAXN || x <= c + bit[s])
      s -= (1 << i);
    else
      c += bit[s];
  }
  add(s + 1, -1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n >> q) {
    memset((bit), 0, sizeof((bit)));
    int tmp;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      add(tmp, 1);
    }
    for (int i = 0; i < q; ++i) {
      cin >> tmp;
      if (tmp > 0) {
        add(tmp, 1);
      } else {
        tmp = 0 - tmp;
        rm(tmp);
      }
    }
    if (bit[1 << 19] == 0) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 1; i <= MAXN; ++i) {
      if (bit[i]) {
        cout << i << endl;
        break;
      }
    }
  }
}
