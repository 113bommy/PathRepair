#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 4;
long long ans;
int a[N];
int tmp[N];
void merge_sort(int l, int r) {
  if (l >= r) return;
  int m = (l + r) / 2;
  merge_sort(l, m);
  merge_sort(m + 1, r);
  int cnt = 0;
  int j = m + 1;
  int i = l;
  int p = l, q = m + 1;
  int d = l;
  while (i <= m && j <= r) {
    if (a[i] > a[j])
      tmp[d++] = a[j++], ans += (m - i + 1);
    else
      tmp[d++] = a[i++];
  }
  while (i <= m) tmp[d++] = a[i++];
  while (j <= r) tmp[d++] = a[j++];
  for (int i = l; i <= r; ++i) a[i] = tmp[i];
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  merge_sort(1, n);
  if (ans % 2 == (3 * n) % 2)
    puts("Petr");
  else
    puts("Um_nik");
  return 0;
}
