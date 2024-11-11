#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;
int N, K;
int a, b, c, d;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> N >> K;
  std::cin >> a >> b >> c >> d;
  if (K <= N || N == 4) {
    return puts("-1"), 0;
  }
  printf("%d %d ", a, c);
  for (int i = 1; i <= N; i++) {
    if (i != a && i != c && i != b && i != d) printf("%d ", i);
  }
  printf("%d %d\n", d, b);
  printf("%d %d ", c, a);
  for (int i = 1; i <= N; i++) {
    if (i != a && i != c && i != b && i != d) printf("%d ", i);
  }
  printf("%d %d\n", b, d);
  return 0;
}
