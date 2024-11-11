#include <bits/stdc++.h>
using namespace std;
int n;
int a[(1 << 22) + 5], b[100005];
int main() {
  scanf("%d", &n);
  memset(a, -1, sizeof a);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x] = x;
    b[i] = x;
  }
  for (int i = 0; i < 22; i++) {
    for (int j = 0; j < (1 << 22); j++) {
      if (j & (1 << i)) {
        if (a[j ^ (1 << i)] != -1) a[j] = a[j ^ (1 << i)];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", a[b[i] ^ ((1 << 22) - 1)]);
  }
}
