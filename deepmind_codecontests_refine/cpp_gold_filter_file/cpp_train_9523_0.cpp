#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int a[MAXN], N, l, r;
long long v;
int main() {
  scanf("%d %I64d", &N, &v), --v;
  l = 1, r = N;
  for (int i = N - 2; i >= 0; --i) {
    if ((v >> i) & 1)
      a[r--] = N - 1 - i;
    else
      a[l++] = N - 1 - i;
  }
  a[l] = N;
  for (int i = 1; i <= N; ++i) printf("%d ", a[i]);
  puts("");
}
