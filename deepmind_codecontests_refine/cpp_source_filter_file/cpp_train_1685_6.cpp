#include <bits/stdc++.h>
using namespace std;
int A[150005];
int st[500000];
int n;
void build(int p, int L, int R) {
  if (L == R) {
    st[p] = L;
  } else {
    build(p * 2, L, (L + R) / 2);
    build(p * 2 + 1, (L + R) / 2 + 1, R);
    int p1 = st[2 * p];
    int p2 = st[2 * p + 1];
    st[p] = A[p1] <= A[p2] ? p1 : p2;
  }
}
int rmq(int p, int L, int R, int i, int j) {
  if (L > j || R < i) {
    return -1;
  }
  if (L >= i && R <= j) {
    return st[p];
  }
  int p1 = rmq(2 * p, L, (L + R) / 2, i, j);
  int p2 = rmq(2 * p + 1, (L + R) / 2 + 1, R, i, j);
  if (p1 == -1) {
    return p2;
  }
  if (p2 == -1) {
    return p1;
  }
  return A[p1] <= A[p2] ? p1 : p2;
}
int rmq(int i, int j) { return rmq(1, 1, n, i, j); }
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> A[i];
    }
    build(1, 1, n);
    int ans = 0;
    for (int i = 1; i < n; i++) {
      int mn = rmq(i + 1, n);
      if (A[mn] < A[i]) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}
