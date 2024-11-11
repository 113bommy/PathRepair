#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, kk, tmp, v;
int mx(int n, int k) { return n > k ? n : k; }
int gao(int v, int k) {
  int sum = 0;
  int tk = 1;
  while (sum <= n && v >= tk) {
    sum += v / tk;
    tk *= k;
  }
  return sum;
}
int judge(int m) {
  if (gao(m, k) < n) return -1;
  if (gao(m - 1, k) >= n) return 1;
  return 0;
}
int bin(int i, int j) {
  int mid = (i + j) / 2;
  if (judge(mid) == 0) return mid;
  if (i >= j) return i;
  if (judge(mid) == -1) return bin(mid + 1, j);
  return bin(i, mid - 1);
}
int main() {
  cin >> n >> k;
  v = bin(1, mx(n, k));
  cout << v;
  return 0;
}
