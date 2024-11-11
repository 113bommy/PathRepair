#include <bits/stdc++.h>
using namespace std;
int n, idx;
bool st[300001];
int main() {
  scanf("%d", &n);
  idx = n;
  printf("1 ");
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    st[x - 1] = true;
    while (idx && st[idx - 1]) idx--;
    printf("%d ", i - (n - idx) + 1);
  }
}
