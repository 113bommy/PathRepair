#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, a, b, len, num;
  cin >> n >> a >> b >> k;
  long long arr[n + 10];
  fill(arr, arr + n + 10, 0);
  if (a > b) {
    len = n - b;
    len++;
    arr[len + b - a] = 1;
  } else {
    len = b;
    arr[a] = 1;
  }
  long long newarr[len], sum[len], way1, way2;
  sum[0] = 0;
  for (i = 1; i < len; i++) sum[i] = sum[i - 1] + arr[i];
  for (i = 0; i < k; i++) {
    fill(newarr, newarr + len, 0);
    for (i = 1; i < len; i++) {
      way1 = sum[i - 1];
      num = (len + i - 1) / 2;
      way2 = sum[num] - sum[i];
      newarr[i] = way1 + way2;
      newarr[i] %= 1000000007;
    }
    for (i = 0; i < len; i++) arr[i] = newarr[i];
    sum[0] = 0;
    for (i = 1; i < len; i++) {
      sum[i] = sum[i - 1] + arr[i];
      sum[i] %= 1000000007;
    }
  }
  long long total;
  total = 0;
  for (i = 1; i < len; i++) {
    total = total + arr[i];
    total %= 1000000007;
  }
  total %= 1000000007;
  total += 1000000007;
  total %= 1000000007;
  cout << total;
}
