#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int N, T, A[MAXN];
int main() {
  scanf("%d", &N), scanf("%d", &T);
  for (int i = 0; i < (int)N; i++) scanf("%d", &A[i]);
  for (int i = 0; i < (int)N; i++) {
    T -= (86400 - A[i]);
    if (T <= 0) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
}
