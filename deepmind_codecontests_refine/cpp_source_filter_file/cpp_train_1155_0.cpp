#include <bits/stdc++.h>
double PI = 3.141592653589793238462643383279502884;
double epsilon = 1e-12;
using namespace std;
long long fast_power_mod(long long b, long long p, long long m) {
  if (p == 0) return 1;
  long long res = fast_power_mod(b, p / 2, m) % m;
  if (p % 2 == 0)
    return ((res) * (res)) % m;
  else
    return ((res) * (res) * (b % m)) % m;
}
long long arthmetic_seq_sum(long long start, long long end, long long terms) {
  return ((start + end) * terms) / 2;
}
long long fast_power(long long b, long long p) {
  if (p == 0) return 1;
  long long res = fast_power(b, p / 2);
  if (p % 2 == 0)
    return res * res;
  else
    return res * res * b;
}
bool doublesComp(double a, double b) { return abs(a - b) <= epsilon; }
bool comp(int a, int b) { return a > b; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  long long arr[n];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ans = arr[0];
  for (long long i = 1; i < n; i++) {
    if (arr[i] == 1)
      ans += arr[i];
    else
      ans += (i * arr[i] - 1) + arr[i];
  }
  cout << ans;
}
