#include <bits/stdc++.h>
using namespace std;
ifstream fin(".in");
int x, ans, y;
int i, j, n, m, a, b, k, unu, zero, c, q, pos, val, start, finish;
string s;
char ans2[100010];
int l, r, t;
bool ok, ok2;
int bun[200010 * 4], stricat[200010 * 4];
clock_t t1, t2;
queue<int> Q;
map<int, int> mip;
void update(int nod, int left, int right) {
  int middle = (left + right) / 2;
  if (left == right) {
    bun[nod] = min(bun[nod] + val, a);
    stricat[nod] = min(stricat[nod] + val, b);
    return;
  }
  if (pos <= middle)
    update(2 * nod, left, middle);
  else
    update(2 * nod + 1, middle + 1, right);
  stricat[nod] = stricat[2 * nod] + stricat[2 * nod + 1];
  bun[nod] = bun[2 * nod] + bun[2 * nod + 1];
}
void query(int arb[], int nod, int left, int right) {
  int middle = (left + right) / 2;
  if (left > finish || right < start) return;
  if (left >= start && right <= finish) {
    ans += arb[nod];
    return;
  }
  query(arb, 2 * nod, left, middle);
  query(arb, 2 * nod + 1, middle + 1, right);
}
int main() {
  cin >> n >> k >> a >> b >> q;
  for (i = 1; i <= q; i++) {
    cin >> c;
    if (c == 1) {
      fin >> pos >> val;
      update(1, 1, n);
    } else {
      fin >> c;
      start = 1;
      finish = c - 1;
      ans = 0;
      if (start <= finish) query(stricat, 1, 1, n);
      start = c + k;
      finish = n;
      if (start <= finish) query(bun, 1, 1, n);
      cout << ans << '\n';
    }
  }
  return 0;
}
