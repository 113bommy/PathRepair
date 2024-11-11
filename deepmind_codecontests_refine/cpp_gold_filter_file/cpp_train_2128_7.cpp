#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
int ans[maxn], c;
pair<int, int> getTwoNum(int k, int lim) {}
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    int num = n / 2;
    if (num > k || (n <= 1 && k > 0)) {
      printf("-1\n");
      continue;
    }
    c = 0;
    if (num == k) {
      for (int i = 0; i < k; i++) {
        ans[c++] = i * 2 + 1;
        ans[c++] = i * 2 + 2;
      }
    } else {
      k -= num - 1;
      ans[c++] = k;
      ans[c++] = k * 2;
      for (int i = 0; i < num - 1; i++) {
        ans[c++] = i * 2 + 1 + k * 2;
        ans[c++] = i * 2 + 2 + k * 2;
      }
    }
    if (n % 2) ans[c++] = 999999999;
    for (int i = 0; i < c; i++) {
      printf("%d%c", ans[i], i == c - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
