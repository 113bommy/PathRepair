#include <bits/stdc++.h>
using namespace std;
void sort(int n, vector<int>& a, vector<long long>& inv,
          vector<long long>& maxInv) {
  vector<int> b;
  b.resize(a.size());
  int N = a.size();
  inv.resize(n + 1, 0);
  maxInv.resize(n + 1, 0);
  for (int i = n - 1; i >= 0; --i) {
    inv[i] = inv[i + 1];
    int size = 1 << (n - i - 1), l, r, tol, tor;
    maxInv[i] = (1 << i) * (1LL << (n - i)) * ((1LL << (n - i)) - 1) / 2;
    for (int j = 0, k = 0; j < N; j += 2 * size) {
      l = j, r = tol = j + size, tor = j + 2 * size;
      while (l < tol && r < tor) {
        if (a[l] <= a[r])
          b[k++] = a[l++];
        else {
          b[k++] = a[r++];
          inv[i] += tol - l;
        }
      }
      while (l < tol) b[k++] = a[l++];
      while (r < tor) b[k++] = a[r++];
      long long neq = 1;
      for (int y = j + 1; y < tor; ++y) {
        if (b[y] == b[y - 1])
          ++neq;
        else {
          maxInv[i] -= neq * (neq - 1) / 2;
          neq = 1;
        }
      }
      maxInv[i] -= neq * (neq - 1) / 2;
    }
    a.swap(b);
  }
}
void transform(vector<long long>& inv, vector<long long>& maxInv, int level) {
  long long prev = inv[level];
  for (int i = inv.size() - 1; i >= level; --i) {
    inv[i] = maxInv[i] - inv[i];
  }
  long long delta = inv[level] - prev;
  for (int i = 0; i < level; ++i) inv[i] += delta;
}
int main() {
  int n, N;
  scanf("%d", &n);
  N = 1 << n;
  vector<int> a(N, 0);
  for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
  vector<long long> inv, maxInv;
  sort(n, a, inv, maxInv);
  int Q;
  scanf("%d", &Q);
  for (int z = 0, q; z < Q; ++z) {
    scanf("%d", &q);
    transform(inv, maxInv, n - q);
    printf("%ld\n", inv[0]);
  }
  return 0;
}
