#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int n;
int p[N << 1];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) p[i] = i;
  int l = 0;
  for (int k = 2; k <= n; ++k) {
    int first = p[l];
    for (int i = l + k; i < l + n; i += k) swap(first, p[i]);
    p[l + n] = first;
    ++l;
  }
  for (int i = n - 1; i < 2 * n - 1; ++i)
    printf("%d%c", p[i] + 1, " \n"[i == 2 * n - 2]);
  return 0;
}
