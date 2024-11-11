#include <bits/stdc++.h>
using namespace std;
int const maxn = 1000005;
int main() {
  int N;
  int a, b;
  while (~scanf("%d", &N)) {
    scanf("%d%d", &a, &b);
    if ((a == N / 2 || a == N / 2 + 1) && (b = N / 2 || b == N / 2 + 1))
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
