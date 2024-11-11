#include <bits/stdc++.h>
using namespace std;
long long tonum(const string &s) {
  stringstream ss;
  ss << s;
  long long x;
  ss >> x;
  return x;
}
string tostring(long long number) {
  stringstream ss;
  ss << number;
  return ss.str();
}
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first < b.first)
    return false;
  else if (a.first > b.first)
    return true;
  return a.second > b.second;
}
bool comp2(long long a, long long b) { return a > b; }
long long a, b, c, d, n, m;
long long func(long long *arr, long long len) {
  long long sum = 0;
  for (int i = 0; i < len; i++) sum += arr[i];
  sum = sum * a;
  long long sum2 = len * b;
  sort(arr, arr + len);
  long long j = len - 1;
  long long sum3 = 0;
  while (j >= 0) {
    if (arr[j] * a > b)
      j--, sum3 += b;
    else {
      for (int k = 0; k <= j; k++) sum += arr[k] * a;
      break;
    }
  }
  return min(c, min(sum, min(sum2, sum3)));
}
int main() {
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  scanf("%lld%lld", &n, &m);
  long long arr[n], arr2[m];
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  for (int i = 0; i < m; i++) scanf("%lld", &arr2[i]);
  printf("%lld\n", min(d, func(arr, n) + func(arr2, m)));
  return 0;
}
