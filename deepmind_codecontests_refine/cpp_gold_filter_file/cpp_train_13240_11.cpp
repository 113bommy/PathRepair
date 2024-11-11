#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int MX = 1 << 18;
int N;
int A[MAXN];
vector<int> v;
int dp1[MAXN], dp2[MAXN];
int seg[MX * 2];
int lazy[MX * 2];
void mkseg(int idx, int l, int r) {
  lazy[idx] = 0;
  if (l == r)
    seg[idx] = (l == 0 ? 1 : 0);
  else {
    int m = (l + r) / 2;
    mkseg(idx * 2, l, m);
    mkseg(idx * 2 + 1, m + 1, r);
    seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
  }
}
void updseg(int idx, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    seg[idx] += z;
    lazy[idx] += z;
  } else if (l <= y && x <= r) {
    int m = (l + r) / 2;
    updseg(idx * 2, l, m, x, y, z);
    updseg(idx * 2 + 1, m + 1, r, x, y, z);
    seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]) + lazy[idx];
  }
}
void updseg(int x, int y, int z) { updseg(1, 0, N - 1, x, y, z); }
int gseg(int idx, int l, int r, int x) {
  if (l == r) return seg[idx];
  int m = (l + r) / 2;
  return (x <= m ? gseg(idx * 2, l, m, x) : gseg(idx * 2 + 1, m + 1, r, x)) +
         lazy[idx];
}
int gseg(int x) { return gseg(1, 0, N - 1, x); }
void f(int dp[]) {
  vector<int> r;
  r.push_back(0);
  mkseg(1, 0, N - 1);
  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    while (v[r.back()] > v[i]) r.pop_back();
    updseg(r.back() + 1, i - 1, 1);
    updseg(i, i, gseg(r.back()) + 1);
    dp[i] = seg[1];
    r.push_back(i);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  int one = 0;
  for (int i = 1; i < N; i++)
    if (A[i] == 1) one = i;
  for (int i = one; i < N; i++) v.push_back(A[i]);
  for (int i = 0; i < one; i++) v.push_back(A[i]);
  f(dp1);
  for (int i = 1; i <= (N - 1) / 2; i++) swap(v[i], v[N - i]);
  f(dp2);
  int mx = 0;
  for (int i = 1; i < N; i++)
    if (max(dp1[i], dp2[N - 1 - i]) < max(dp1[mx], dp2[N - 1 - mx])) mx = i;
  cout << max(dp1[mx], dp2[N - 1 - mx]) << " " << ((one + mx + 1) % N);
  return 0;
}
