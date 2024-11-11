#include <bits/stdc++.h>
const int inf = 1000000007;
const double pi = 2 * acos(0.0);
using namespace std;
int gcd(int a, int b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
int main() {
  map<long long, int> m;
  long long n, k;
  scanf("%lld%lld", &n, &k);
  long long arr[n];
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    m.insert(make_pair(arr[i], 1));
  }
  vector<long long> ans;
  long long sum = 0;
  for (int i = 1; i < 1e9; i++) {
    if (sum > k) {
      ans.pop_back();
      break;
    }
    if (m[i] != 1) {
      sum += i;
      ans.push_back(i);
    }
  }
  printf("%d\n", ans.size());
  for (long long i : ans) {
    printf("%d ", i);
  }
}
