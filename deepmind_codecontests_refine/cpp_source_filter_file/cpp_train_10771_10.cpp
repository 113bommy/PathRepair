#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, a[maxn], b[maxn], sgmnt[maxn], A[maxn], B[maxn];
void Build(int v = 1, int l = 0, int r = n - 1) {
  sgmnt[v] = r - l + 1;
  int mid = l + r >> 1;
  if (l < r) {
    Build(v * 2, l, mid);
    Build(v * 2 + 1, mid + 1, r);
  }
}
void Delete(int id, int v = 1, int l = 0, int r = n - 1) {
  sgmnt[v]--;
  if (l < r) {
    int mid = l + r >> 1;
    if (id <= mid)
      Delete(id, v * 2, l, mid);
    else
      Delete(id, v * 2 + 1, mid + 1, r);
  }
}
int Sum(int L, int R, int v = 1, int l = 0, int r = n - 1) {
  if (L > R) return 0;
  if (l == L && r == R) return sgmnt[v];
  int mid = l + r >> 1, tmp = 0;
  if (l <= mid) tmp += Sum(L, min(R, mid), v * 2, l, mid);
  if (mid + 1 <= r) tmp += Sum(max(L, mid + 1), R, v * 2 + 1, mid + 1, r);
  return tmp;
}
int Val(int id, int v = 1, int l = 0, int r = n - 1) {
  if (l == r) return l;
  int mid = l + r >> 1;
  if (id < sgmnt[v * 2])
    return Val(id, 2 * v, l, mid);
  else
    return Val(id - sgmnt[2 * v], 2 * v + 1, mid + 1, r);
}
void Create(int a[], int arr[]) {
  Build();
  for (int i = n - 1; i >= 0; i--) {
    arr[i] = Sum(0, a[i] - 1);
    Delete(a[i]);
  }
}
int32_t main() {
  cin >> n;
  for (int i = n - 1; i >= 0; i--) cin >> a[i];
  for (int i = n - 1; i >= 0; i--) cin >> b[i];
  Create(a, A);
  Create(b, B);
  for (int i = 0; i < n; i++)
    A[i] += B[i], A[i + 1] += A[i] / (i + 1), A[i] %= i + 1;
  Build();
  for (int i = n - 1; i >= 0; i--) {
    int tmp = Val(A[i]);
    cout << tmp << " ";
    Delete(tmp);
  }
}
