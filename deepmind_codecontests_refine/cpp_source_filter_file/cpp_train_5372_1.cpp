#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
inline long long int max(long long int a, long long int b) {
  return ((a > b) ? a : b);
}
inline long long int min(long long int a, long long int b) {
  return ((a > b) ? b : a);
}
inline long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
long long int n, k;
vector<long long int> a(MAXN);
vector<long long int> v;
map<long long int, long long int> mp;
map<long long int, long long int> mp1;
void PrimeFactorisation(long long int k) {
  long long int count = 0;
  while (k % 2 == 0) count++, k = k / 2;
  if (count) mp[2] = count;
  for (long long int i = 3; i <= sqrt(k); i++) {
    count = 0;
    while (k % i == 0) count++, k = k / i;
    if (count) mp[i] = count;
  }
  if (k > 2) mp[k] = 1;
}
void sol() {
  long long int i;
  cin >> n >> k;
  if (k == 1) {
    cout << (n * (n + 1)) / 2;
    return;
  }
  PrimeFactorisation(k);
  for (i = 0; i < n; i++) cin >> a[i];
  long long int left = 0;
  for (i = 0; i < n; i++) {
    long long int x = a[i];
    for (auto j : mp) {
      long long int count = 0;
      while (x % j.first == 0) count++, x = x / j.first;
      mp1[j.first] += count;
    }
    long long int f = 0;
    for (auto j : mp) {
      if (j.second > mp1[j.first]) f = 1;
    }
    if (f == 0) break;
  }
  if (i == n) {
    cout << 0;
    return;
  }
  long long int right = i;
  long long int ans = 0;
  ans += (n - right);
  for (i = 0; i < n - 1; i++) {
    long long int x = a[i];
    for (auto j : mp) {
      long long int count = 0;
      while (x % j.first == 0) count++, x = x / j.first;
      mp1[j.first] -= count;
    }
    long long int f = 0;
    for (auto j : mp) {
      if (j.second > mp1[j.first]) f = 1;
    }
    if (f == 0) {
      ans += (n - right);
      continue;
    }
    while ((right + 1) < n) {
      right++;
      long long int x = a[right];
      for (auto j : mp) {
        long long int count = 0;
        while (x % j.first == 0) count++, x = x / j.first;
        mp1[j.first] += count;
      }
      long long int f = 0;
      for (auto j : mp) {
        if (j.second > mp1[j.first]) f = 1;
      }
      if (f == 0) {
        ans += (n - right);
        continue;
      }
    }
  }
  cout << ans;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sol();
}
