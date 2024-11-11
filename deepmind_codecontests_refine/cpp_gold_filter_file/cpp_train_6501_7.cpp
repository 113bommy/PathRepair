#include <bits/stdc++.h>
using namespace std;
int Pow(int a, int b, int md, int ans = 1) {
  for (; b; b >>= 1, a = a * a % md)
    if (b & 1) ans = ans * a % md;
  return ans % md;
}
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
const int SQ = 512;
const int tof = 511;
template <class T, int SZ>
struct FastDeque {
  T Q[SZ * 2 + 10];
  int l = SZ, r = SZ;
  void push_back(T x) { Q[r++] = x; }
  void push_front(T x) { Q[--l] = x; }
  void pop_front() { l++; }
  void pop_back() { r--; }
  T front() { return Q[l]; }
  T back() { return Q[r - 1]; }
  void clear() { l = r = SZ; }
  bool empty() { return (l == r); }
  T get(int id) { return Q[l + id]; }
};
deque<int> dq[SQ];
int cnt[SQ][MAXN], A[MAXN], n, q, lst;
void updsame(int l, int r) {
  int x = dq[l / SQ][r & tof];
  for (int i = r & tof; i > (l & tof); i--) {
    dq[l / SQ][i] = dq[l / SQ][i - 1];
  }
  dq[l / SQ][l & tof] = x;
}
void updnot(int l, int r) {
  for (int i = l - (l & tof) + SQ - 1; i < r; i += SQ) {
    int x = dq[i / SQ].back();
    dq[i / SQ].pop_back();
    dq[i / SQ + 1].push_front(x);
    cnt[i / SQ][x]--;
    cnt[i / SQ + 1][x]++;
  }
  int x = dq[r / SQ][(r & tof) + 1];
  for (int i = (r & tof); i >= 0; i--) dq[r / SQ][i + 1] = dq[r / SQ][i];
  dq[r / SQ].pop_front();
  dq[l / SQ].push_back(x);
  for (int i = SQ - 1; i > (l & tof); i--) dq[l / SQ][i] = dq[l / SQ][i - 1];
  cnt[r / SQ][x]--, cnt[l / SQ][x]++;
  dq[l / SQ][l & tof] = x;
}
void update(int l, int r) {
  if (l == r) return;
  if (r / SQ == l / SQ)
    updsame(l, r);
  else
    updnot(l, r);
}
int get(int l, int r, int x, int ans = 0) {
  for (int i = l; i <= r;) {
    if ((i & tof) == 0 && i + SQ - 1 <= r) {
      ans += cnt[i / SQ][x];
      i += SQ;
    } else {
      if (dq[i / SQ][i & tof] == x) ans++;
      i++;
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    cnt[i / SQ][A[i]]++;
    dq[i / SQ].push_back(A[i]);
  }
  scanf("%d", &q);
  while (q--) {
    int l, r, t, x;
    scanf("%d%d%d", &t, &l, &r);
    l = (l + lst - 1) % n + 1;
    r = (r + lst - 1) % n + 1;
    if (r < l) swap(l, r);
    l--, r--;
    if (t == 1) {
      update(l, r);
    } else {
      scanf("%d", &x);
      x = (x + lst - 1) % n + 1;
      lst = get(l, r, x);
      printf("%d\n", lst);
    }
  }
  return 0;
}
