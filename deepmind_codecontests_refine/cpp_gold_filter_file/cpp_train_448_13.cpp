#include <bits/stdc++.h>
using namespace std;
vector<int> cp;
void init() {
  int i, t = 1;
  cp.push_back(t);
  while (t < 100001) {
    t *= 2;
    cp.push_back(t);
  }
}
int BST(int x, int L, int R) {
  if (R - L < 2) {
    if (cp[R] <= x) return R;
    if (cp[L] > x) return (L - 1);
    return L;
  }
  int tg = (R + L) / 2;
  if (cp[tg] == x) return tg;
  if (cp[tg] > x) return BST(x, L, tg - 1);
  return BST(x, tg + 1, R);
}
int main() {
  int i, j, n, a[100001];
  long long rt = 0;
  init();
  int m = cp.size();
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i + 1];
  }
  for (i = 1; i < n; i++) {
    j = BST(n - i, 0, m - 1);
    rt += a[i];
    a[cp[j] + i] += a[i];
    a[i] = 0;
    if (i < n - 1)
      cout << rt << endl;
    else
      cout << rt;
  }
}
