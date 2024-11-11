#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> arr(n + 2);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  arr[n + 1] = 1001;
  int prev = 0;
  int len = 1;
  int maxlen = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (prev == arr[i] - 1) {
      len++;
    } else {
      len = 1;
    }
    prev = arr[i];
    maxlen = max(len, maxlen);
  }
  printf("%d\n", maxlen - 2);
  return 0;
}
