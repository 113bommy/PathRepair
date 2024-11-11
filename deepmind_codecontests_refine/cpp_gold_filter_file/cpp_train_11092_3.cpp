#include <bits/stdc++.h>
using namespace std;
long long INV2 = 500000004;
long long INV6 = 166666668;
long long power(long long a, long long b, long long c) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b & 1) x = (x * y) % c;
    y = (y * y) % c;
    b /= 2;
  }
  return x % c;
}
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<long long> le, ri;
long long solve(long long val) {
  long long lo = 0, hi = ri.size();
  long long ans = -1;
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (ri[mid] < val) {
      ans = ri[mid];
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  long long num;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &num);
    if (s[i] == 'L')
      le.push_back(num);
    else
      ri.push_back(num);
  }
  long long ans = 1e16;
  for (int i = 0; i < le.size(); ++i) {
    long long ele = le[i];
    long long val = solve(ele);
    if (val != -1) {
      long long dekh = (ele - val) / 2;
      ans = min(ans, 1LL * dekh);
    }
  }
  if (ans < 1e16)
    printf("%lld\n", ans);
  else {
    printf("-1\n");
  }
  return 0;
}
