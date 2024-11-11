#include <bits/stdc++.h>
using namespace std;
unsigned long long mod = 1e9 + 7;
unsigned long long ncr(long long int n, long long int k) {
  unsigned long long res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
    res = res % mod;
  }
  return res % mod;
}
bool prime(unsigned long long num) {
  bool flag = true;
  for (unsigned long long i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
long long ipow(long long base, long long exp) {
  long long result = 1;
  for (;;) {
    if (exp & 1) {
      result *= base;
      result = result % mod;
    }
    exp >>= 1;
    if (!exp) break;
    base *= base;
    base = base % mod;
  }
  return result % mod;
}
long long abs(long long a, long long b) {
  if ((a - b) > 0)
    return (a - b);
  else
    return (b - a);
}
int main() {
  int n;
  cin >> n;
  set<int> r, l;
  vector<int> ri, li;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (r.find(arr[i]) == r.end()) {
      ri.push_back(i);
      r.insert(arr[i]);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (l.find(arr[i]) == l.end()) {
      li.push_back(i);
      l.insert(arr[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < li.size(); i++) {
    int v = li[i];
    int t = lower_bound(ri.begin(), ri.end(), v) - ri.begin();
    ans += t;
  }
  cout << ans;
}
