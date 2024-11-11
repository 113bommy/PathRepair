#include <bits/stdc++.h>
using namespace std;
long long pwr(long long a, long long n) {
  if (!n) return 1;
  if (!a) return 0;
  if (n == 1) return a;
  long long ans = 1;
  if (n % 2) ans = a;
  return ans * pwr(a * a, n / 2);
}
long long gcd(long long a, long long b) {
  if (a > b) {
    long long tmp = a;
    a = b;
    b = tmp;
  }
  while (a) {
    long long tmp = b % a;
    b = a;
    a = tmp;
  }
  return b;
}
int main() {
  ios::sync_with_stdio(0);
  long long i, k, val = 0;
  cin >> k;
  long long low = 0, high = 50;
  long long ans, mx;
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long val = 1;
    for (i = 0; i < 10; i++) val *= mid;
    if (val <= k) {
      mx = val;
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  string s = "codeforces";
  vector<long long> v(10, 0);
  for (i = 0; i < 10; i++) v[i] = ans;
  for (i = 0; i < 10; i++) {
    if (mx >= k) break;
    v[i]++;
    mx = (mx / ans) * (ans + 1);
  }
  string f = "";
  for (i = 0; i < 10; i++) {
    for (int j = 0; j < v[i]; j++) f = f + s[i];
  }
  cout << f << endl;
}
