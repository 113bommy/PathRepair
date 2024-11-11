#include <bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int sum[1050];
int prev(int x) { return x & (x - 1); }
int next(int x) { return (x << 1) - prev(x); }
int find_sum(int x) {
  int ret = 0;
  while (x) {
    ret += sum[x];
    x = prev(x);
  }
  return ret;
}
void modify(int x) {
  while (x < 1050) {
    sum[x]++;
    x = next(x);
  }
}
int find_sum(int a, int b) { return find_sum(b) - find_sum(a - 1); }
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (find_sum(j + k, n) >= b[j]) {
        a[i] = j;
        b[j] = 1 << 30;
        modify(j);
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
