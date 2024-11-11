#include <bits/stdc++.h>
using namespace std;
vector<long long> divisor(long long n) {
  vector<long long> v;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        v.push_back(i);
      else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  return v;
}
bool isprime(int n) {
  int i;
  for (i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
vector<long long> sieve() {
  vector<long long> v(1000001);
  int i, j;
  for (i = 0; i < 1000001; i++) v[i] = 1;
  for (i = 2; i <= sqrt(1000001); i++)
    if (v[i] == 1)
      for (j = i * i; j <= 1000000; j += i) v[j] = 0;
  v[1] = 0;
  return v;
}
bool checkpalindrome(string s) {
  string rev = s;
  reverse(s.begin(), s.end());
  if (rev == s) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long a, b = 31, c, d, e, sum = 0, count = 0, flag = 0, j = 0, i = 1;
  long long x, y;
  set<long long> se;
  long long n, m, t, k, l, r;
  string s;
  vector<long long> v;
  cin >> n >> m;
  long long freq[100] = {0};
  long long arr[n], brr[m];
  for (i = 0; i < n; i++) cin >> arr[i], freq[arr[i]]++;
  for (i = 0; i < m; i++) cin >> brr[i], freq[brr[i]]++;
  for (i = 0; i < 100; i++) {
    if (freq[i] > 1) {
      cout << i;
      return 0;
    }
  }
  sort(arr, arr + n);
  sort(brr, brr + m);
  a = min(arr[0], brr[0]);
  b = max(arr[0], brr[0]);
  cout << a << b;
}
