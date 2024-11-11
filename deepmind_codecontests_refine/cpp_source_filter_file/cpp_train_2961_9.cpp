#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2000000000;
const long long BIG = 1446803456761533460LL;
const int maxn = 100010;
const int second = 1300;
int n, q, m, bn, A[maxn], qs[maxn][3], comp[maxn * 2];
struct Block {
  int fen[maxn], cnt[maxn * 2];
  void update(int i, int v) {
    for (++i; i < maxn; i += i & -i) fen[i] += v;
  }
  int get(int i) {
    int v = 0;
    for (++i; i; i ^= i & -i) v += fen[i];
    return v;
  }
  void change(int x, int d) {
    update(cnt[x], -1);
    cnt[x] += d;
    update(cnt[x], 1);
  }
  int atleast(int x) { return m - get(x - 1); }
} block[maxn / second + 5];
int getid(int x) { return lower_bound(comp, comp + m, x) - comp; }
void change(int p, int x, int d) {
  for (int i = p / second + 1; i < bn; ++i) {
    block[i].change(x, d);
  }
}
int getA2(int p) {
  ++p;
  int ii = p / second;
  for (int i = ii * second; i < p; ++i) block[ii].cnt[A[i]]++;
  int res = block[ii].cnt[A[p - 1]];
  for (int i = ii * second; i < p; ++i) block[ii].cnt[A[i]]--;
  return res;
}
int getA3(int p) {
  int c = getA2(p);
  ++p;
  int ii = p / second;
  int res = block[ii].atleast(c);
  for (int i = ii * second; i < p; ++i)
    if (++block[ii].cnt[A[i]] == c) ++res;
  for (int i = ii * second; i < p; ++i) block[ii].cnt[A[i]]--;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    comp[i] = A[i];
  }
  m = n;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> qs[i][0] >> qs[i][1] >> qs[i][2];
    if (qs[i][0] == 1) comp[m++] = qs[i][2];
  }
  sort(comp, comp + m);
  m = unique(comp, comp + m) - comp;
  bn = n / second + 1;
  for (int i = 0; i < bn; ++i) block[i].update(0, m);
  for (int i = 0; i < n; ++i) {
    A[i] = getid(A[i]);
    change(i, A[i], 1);
  }
  for (int i = 0; i < q; ++i) {
    if (qs[i][0] == 1) {
      int p = qs[i][2] - 1;
      int v = getid(qs[i][1]);
      change(p, A[p], -1);
      A[p] = v;
      change(p, A[p], 1);
    } else if (qs[i][1] == 1) {
      cout << comp[A[qs[i][2] - 1]] << '\n';
    } else if (qs[i][1] % 2 == 0) {
      cout << getA2(qs[i][2] - 1) << '\n';
    } else {
      cout << getA3(qs[i][2] - 1) << '\n';
    }
  }
}
