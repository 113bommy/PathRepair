#include <bits/stdc++.h>
using namespace std;
int bitsCount[40];
int numberBits(int num) {
  int cnt = 0;
  while (num > 0) {
    cnt++;
    num = num >> 1;
  }
  return cnt;
}
long long findSum(int n) {
  if (n == 0 || n == 1) return 0;
  long long num = (long long)n;
  return (num * (num - 1)) / 2;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, temp;
    scanf("%d", &n);
    memset(bitsCount, 0, sizeof(bitsCount));
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      bitsCount[numberBits(temp)]++;
    }
    long long ans = 0;
    for (int i = 0; i < 40; i++) ans += findSum(bitsCount[i]);
    printf("%lld\n", ans);
  }
  return 0;
}
