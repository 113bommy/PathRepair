#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 20, mod = 998244353;
long long n, a[maxn], part[maxn], Inv[maxn], fact[maxn], b[maxn / 10],
    A[maxn / 10], Sum, Ans, seg[maxn];
pair<int, int> lz[maxn];
vector<int> su;
void upd(int i, int j, int x, int a1, int q) {
  seg[x] += (j - i) * (a1 + a1 + q * (j - i - 1)) / 2;
  lz[x] = pair<int, int>(lz[x].first + a1, lz[x].second + q);
}
void shift(int i, int j, int x) {
  int md = (i + j) >> 1;
  upd(i, md, x * 2, lz[x].first, lz[x].second);
  upd(md, j, x * 2 + 1, lz[x].first + lz[x].second * (md - i), lz[x].second);
  lz[x] = pair<int, int>(0, 0);
}
void add(int i, int j, int x, int l, int r, int a1, int q) {
  if (i >= r || j <= l || i >= j || l >= r) return;
  if (i >= l && j <= r) {
    upd(i, j, x, a1 + q * (i - l), q);
    return;
  }
  shift(i, j, x);
  int md = (i + j) >> 1;
  add(i, md, x * 2, l, r, a1, q);
  add(md, j, x * 2 + 1, l, r, a1, q);
  seg[x] = seg[x * 2] + seg[x * 2 + 1];
}
void get(int i, int j, int x) {
  if (i + 1 == j) {
    su.push_back(seg[x]);
    return;
  }
  shift(i, j, x);
  int md = (i + j) >> 1;
  get(i, md, x * 2), get(md, j, x * 2 + 1);
}
long long Pow(int i, int j) {
  if (!j) return 1;
  long long ret = Pow(i, j / 2);
  ret = (ret * ret) % mod;
  if (j & 1) ret = (ret * i) % mod;
  return ret;
}
void get_f_i() {
  fact[0] = Inv[0] = 1;
  for (int y = 1; y < maxn; y++)
    fact[y] = (fact[y - 1] * y) % mod, Inv[y] = Pow(fact[y], mod - 2);
}
long long C(int i, int j) {
  if (i < 0 || i > j) return 0;
  long long ret = fact[j];
  ret = (ret * Inv[i]) % mod;
  ret = (ret * Inv[j - i]) % mod;
  return ret;
}
void solve_1(long long i) {
  for (int y = 1; y <= n; y++) {
    add(0, i + 1, 1, 0, min(A[y] + 1, i + 1), A[y], -1);
    if (A[y] < i) add(0, i + 1, 1, A[y] + 1, i + 1, n - 1, -1);
  }
  get(0, i + 1, 1);
  for (auto AA : su) {
    int k = (Sum - AA) / n;
    Ans = (Ans + C(n - 1, n - 1 + k)) % mod;
  }
  cout << Ans;
}
void solve_2() {
  for (int y = 1; y <= n; y++) {
    A[y] %= n;
    add(0, n, 1, 0, n - A[y], A[y], 1);
    add(0, n, 1, n - A[y], n, 0, 1);
  }
  get(0, n, 1);
  for (auto AA : su) {
    int k = (Sum - AA) / n;
    Ans = (Ans + C(n - 1, n - 1 + k)) % mod;
  }
  cout << Ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int y = 1; y <= n; y++) {
    cin >> A[y];
    Sum += A[y];
    a[A[y]]++;
  }
  part[0] = a[0];
  for (int y = 1; y < maxn; y++) part[y] = part[y - 1] + a[y];
  get_f_i();
  for (int y = 0; y < n; y++)
    if (part[y] > y + 1) {
      solve_1(y);
      return 0;
    }
  solve_2();
  return 0;
}
