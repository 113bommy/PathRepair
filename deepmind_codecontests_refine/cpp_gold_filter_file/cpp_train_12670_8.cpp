#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void solve() {
  int n;
  long long number[200010];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &number[i]);
  }
  long long sum1 = 0;
  long long sum3 = 0;
  long long max = 0;
  int l = 0, r = n - 1;
  while (l <= r) {
    if (sum1 < sum3) {
      sum1 += number[l];
      l++;
    }
    if (sum1 > sum3) {
      sum3 += number[r];
      r--;
    }
    if (sum1 == sum3) {
      if (sum1 > max) max = sum1;
      sum1 += number[l];
      l++;
    }
  }
  printf("%lld\n", max);
}
int main() {
  long long l, r, a, b, x, y, G, L, i, j;
  scanf("%lld %lld %lld %lld", &l, &r, &a, &b);
  vector<int> v;
  for (i = 1; i * i <= b; i++) {
    if (b % i == 0) {
      v.push_back(i);
      if (i != b / i) v.push_back(b / i);
    }
  }
  sort(v.begin(), v.end());
  int len = v.size();
  int ans = 0;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      x = v[i], y = v[j];
      G = gcd(x, y);
      L = (x * y) / G;
      if (G == a && L == b && x >= l && x <= r && y >= l && y <= r) ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
