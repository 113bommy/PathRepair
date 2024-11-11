#include <bits/stdc++.h>
using namespace std;
long long int powmod(long long int a, int b, int n) {
  long long int rm = 1;
  while (b) {
    if (b % 2) {
      rm = (rm * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return rm;
}
int a[int(1e6 + 10)], seg[4 * int(1e6 + 10)] = {0}, n, Q, length = 0, q,
                                        ans[int(1e6 + 10)], fakelength = 0;
void Add(int n, int it, int f, int q) {
  seg[n]++;
  if (it == f) return;
  int m = (it + f) / 2;
  if (q <= m)
    Add(n * 2, it, m, q);
  else
    Add(n * 2 + 1, m + 1, f, q);
}
void remove(int n, int it, int f, int pos) {
  seg[n]--;
  if (it == f) return;
  int m = (it + f) / 2;
  if (seg[n * 2] >= pos)
    remove(n * 2, it, m, pos);
  else
    remove(n * 2 + 1, m + 1, f, pos - seg[n * 2]);
}
int query(int n, int it, int f, int q) {
  if (it == f) return seg[n];
  int m = (it + f) / 2;
  if (q <= m) return query(2 * n, it, m, q);
  return query(n * 2 + 1, m + 1, f, q);
}
int m;
int main() {
  cin >> Q >> n;
  m = Q;
  for (int i = int(1); i <= (int)n; i++) scanf("%d", &a[i]);
  ;
  long long int id;
  int ct = 0;
  while (Q--) {
    ++ct;
    scanf("%d", &q);
    ;
    if (q == -1) {
      if (a[1] > length) {
        continue;
      }
      id = (upper_bound(a + 1, a + n + 1, length) - a);
      id--;
      for (int i = id; i >= 1; i--) {
        remove(1, 1, m, a[i]);
      }
      length -= id;
    } else if (!q) {
      ++fakelength;
      ++length;
      ans[fakelength] = 0;
      Add(1, 1, m, fakelength);
    } else {
      ++fakelength;
      ++length;
      ans[fakelength] = 1;
      Add(1, 1, m, fakelength);
    }
  }
  if (!length) {
    printf("Poor stack!\n");
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    if (query(1, 1, m, i)) {
      printf("%d", ans[i]);
    }
  }
  printf("\n");
  return 0;
}
