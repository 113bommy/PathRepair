#include <bits/stdc++.h>
using namespace std;
const int dl = 10069;
void bib() {
  for (int i = 0; i < (int)10; i++) {
    cout << "\a";
  }
}
const int M = 2 * 3 * 100 * 1000 + 10;
int seg[M];
int ans[M / 2];
int n, m;
void battle(int s, int e, int winner, int l = 0, int r = n, int id = 1) {
  if (s >= r || e <= l) return;
  if (seg[id] != -1) return;
  if (s <= l && r <= e && (winner < l || winner >= r)) {
    seg[id] = winner;
  }
  if (r - l < 2) return;
  int mid = (r + l) / 2;
  battle(s, e, winner, l, mid, id * 2);
  battle(s, e, winner, mid, r, id * 2 + 1);
}
void print(int l = 0, int r = n, int id = 1) {
  if (r - l == 1) {
    ans[l] = seg[id] + 1;
    return;
  }
  int mid = (l + r) / 2;
  print(l, mid, id * 2);
  print(mid, r, id * 2 + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < (int)2 * n; i++) seg[i] = -1;
  for (int i = 0; i < (int)m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    x--;
    battle(l, r, x);
  }
  print();
  for (int i = 0; i < (int)n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
