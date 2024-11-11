#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
using namespace std;
int num[maxn];
int n;
int slove(int i) {
  if (i == n) return num[n];
  return max(slove(i + 1), num[i] - slove(i + 1));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    num[i] += num[i - 1];
  }
  printf("%d\n", slove(2));
}
