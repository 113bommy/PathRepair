#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b > a) return gcd(b, a);
  return b == 0 ? a : gcd(b, a % b);
}
void swap(int *m, int *n) {
  int temp = *n;
  *n = *m;
  *m = temp;
}
struct sort_pred {
  bool operator()(const std::pair<int, int> &left,
                  const std::pair<int, int> &right) {
    return left.first < right.first;
  }
};
int compare(const void *a, const void *b) {
  const int *ia = (const int *)a;
  const int *ib = (const int *)b;
  return *ia - *ib;
}
int main() {
  int c1, c2, c3, c4;
  scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
  int n, m;
  scanf("%d %d", &n, &m);
  int bus[n], trolley[m];
  long long int buscost = 0, trolleycost = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &bus[i]);
    if (c1 * bus[i] < c2)
      buscost = (long long)buscost + (long long)c1 * bus[i];
    else
      buscost += c2;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &trolley[i]);
    if (c1 * trolley[i] < c2)
      trolleycost = (long long)trolleycost + (long long)c1 * trolley[i];
    else
      trolleycost += c2;
  }
  if (buscost > c3) buscost = c3;
  if (trolleycost > c3) trolleycost = c3;
  long long int ans = buscost + trolleycost;
  if (ans < c4)
    cout << ans << endl;
  else
    cout << c4 << endl;
  return 0;
}
