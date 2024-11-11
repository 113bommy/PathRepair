#include <bits/stdc++.h>
using namespace std;
namespace RenaMoe {
template <typename T>
inline void read(T &x) {
  x = 0;
  bool f = false;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  if (f) x = -x;
}
const int N = 2e6 + 9;
const int P = 1e9 + 7;
int n, m, k;
char str[N];
int last[30];
long long f[N];
inline void main() {
  read(n), read(k);
  scanf("%s", str + 1);
  m = strlen(str + 1);
  for (int i = 1; i <= m; ++i) {
    int c = str[i] - '0';
    if (!last[c])
      f[i] = (f[i - 1] * 2ll + 1) % P;
    else
      f[i] = (f[i - 1] * 2ll % P - f[last[c] - 1] + P) % P;
    last[c] = i;
  }
  for (int i = m + 1; i <= m + n; ++i) {
    int c = 0;
    for (int j = 1; j < k; ++j)
      if (last[j] < last[c]) c = j;
    if (!last[c])
      f[i] = (f[i - 1] * 2ll + 1) % P;
    else
      f[i] = (f[i - 1] * 2ll % P - f[last[c] - 1] + P) % P;
    last[c] = i;
  }
  printf("%lld\n", (f[n + m] + 1) % P);
}
}  // namespace RenaMoe
int main() { RenaMoe::main(); }
