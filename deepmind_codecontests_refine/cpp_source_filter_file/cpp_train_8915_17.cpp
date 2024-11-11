#include <bits/stdc++.h>
using namespace std;
map<int, int> comp;
void compress(const vector<int>& a) {
  vector<int> z;
  for (int i = 0; i < a.size(); i++) {
    z.push_back(a[i] - i);
    z.push_back(a[i] - i + 1);
  }
  sort(z.begin(), z.end());
  z.erase(unique(z.begin(), z.end()), z.end());
  for (int i = 0; i < z.size(); i++) comp[z[i]] = i;
}
const int N = 400043;
const int M = 8000043;
int T[4 * N];
int* where[M];
int val[M];
int st;
void change(int& x, int y) {
  where[st] = &x;
  val[st] = x;
  st++;
  x = y;
}
void rollback(int new_st) {
  while (st > new_st) {
    st--;
    *(where[st]) = val[st];
  }
}
void upd(int v, int l, int r, int pos, int val) {
  change(T[v], max(T[v], val));
  if (l < r - 1) {
    int mid = (l + r) / 2;
    if (pos < mid)
      upd(v * 2 + 1, l, mid, pos, val);
    else
      upd(v * 2 + 2, mid, r, pos, val);
  }
}
int query(int v, int l, int r, int L, int R) {
  if (L >= R) return 0;
  if (l == L && r == R) return T[v];
  int mid = (l + r) / 2;
  return max(query(v * 2 + 1, l, mid, L, min(R, mid)),
             query(v * 2 + 2, mid, r, max(L, mid), R));
}
int T2[4 * N];
void upd2(int v, int l, int r, int pos, int val) {
  T2[v] = max(T2[v], val);
  if (l < r - 1) {
    int mid = (l + r) / 2;
    if (pos < mid)
      upd2(v * 2 + 1, l, mid, pos, val);
    else
      upd2(v * 2 + 2, mid, r, pos, val);
  }
}
int query2(int v, int l, int r, int L, int R) {
  if (L >= R) return 0;
  if (l == L && r == R) return T2[v];
  int mid = (l + r) / 2;
  return max(query2(v * 2 + 1, l, mid, L, min(R, mid)),
             query2(v * 2 + 2, mid, r, max(L, mid), R));
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  compress(a);
  int mx = comp.size();
  int ans = 0;
  vector<int> states;
  for (int i = n - 1; i > 0; i--) {
    states.push_back(st);
    int cur = comp[a[i] - i + 1];
    int val = query(0, 0, mx, cur, mx);
    upd(0, 0, mx, cur, val + 1);
  }
  ans = max(ans, query(0, 0, mx, 0, mx));
  for (int i = 0; i < n - 1; i++) {
    rollback(states.back());
    states.pop_back();
    int cur = comp[a[i] - i];
    int val = query2(0, 0, mx, 0, cur);
    upd2(0, 0, mx, cur, val + 1);
    ans = max(ans, val + 1 + query(0, 0, mx, cur, mx));
  }
  cout << n - 1 - ans << endl;
}
