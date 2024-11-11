#include <bits/stdc++.h>
using namespace std;
long long sum[100005];
long long func(int a, int b) {
  if (b < a) return 0;
  if (a == 0) return sum[b];
  return sum[b] - sum[0];
}
int main() {
  int n, l, r, q1, q2, w[100005];
  scanf("%d", &n);
  scanf("%d", &l);
  scanf("%d", &r);
  scanf("%d", &q1);
  scanf("%d", &q2);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    if (i == 0)
      sum[i] = w[i];
    else
      sum[i] = sum[i - 1] + w[i];
  }
  long long sum1, sum2, sum3;
  long long min = 100000000000000;
  int left, right;
  for (int i = -1; i < n; i++) {
    sum1 = func(0, i) * l;
    sum2 = func(i + 1, n - 1) * r;
    sum3 = sum1 + sum2;
    left = i + 1;
    right = n - left;
    if (left > right) {
      sum3 = sum3 + (left - right - 1) * q1;
    } else if (right > left) {
      sum3 = sum3 + (right - left - 1) * q2;
    }
    if (sum3 < min) min = sum3;
  }
  cout << min << "\n";
  return 0;
}
