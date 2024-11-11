#include <bits/stdc++.h>
using namespace std;
long long int mod_Expo(long long int x, long long int n, long long int M) {
  if (x == 0) return 0;
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return mod_Expo((x * x) % M, n / 2, M);
  else
    return (x * mod_Expo((x * x) % M, (n - 1) / 2, M)) % M;
}
long long int binaryExponentiation(long long int x, long long int n) {
  if (x == 0) return 0;
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return binaryExponentiation(x * x, n / 2);
  else
    return x * binaryExponentiation(x * x, (n - 1) / 2);
}
long long int GCD(long long int A, long long int B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
bool prime_check(long long int x) {
  bool prime = (x >= 2);
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      prime = false;
      break;
    }
  }
  return prime;
}
long long int min1(long long int a, long long int b, long long int c) {
  vector<long long int> v1, v2, v3;
  v1.push_back(b);
  v1.push_back(c);
  v1.push_back(a);
  sort(v1.begin(), v1.end());
  return v1[0];
}
long long int min(long long int a, long long int b) {
  if (a <= b)
    return a;
  else
    return b;
}
long long int bin_search(long long int x, long long int low, long long int high,
                         vector<long long int> v1) {
  while (high > low) {
    long long int mid = low + (high - low) / 2;
    if (v1[mid] > x)
      high = mid;
    else
      low = mid + 1;
  }
  return high;
}
long long int digitsum(long long int n) {
  long long int sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, i, j, t, f = 0, g = 0, x, y, z, k, a = 0, b = 0, c = 0, q,
                               x1, x2, y1, y2, x3, max2, min1 = 1000000, x4,
                               sum, d, M = 998244353, r, p, sum1 = 0, sum2 = 0,
                               sum3 = 0, sum4, sum5, max1 = 0, sum6;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int arr[n], arr1[n];
    f = 0;
    set<long long int> s;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
      s.insert(arr[i]);
      arr1[i] = arr[i];
    }
    sort(arr1, arr1 + n);
    for (i = n - 1; i >= 0; i--) {
      if (arr1[i] == arr[n - 1 - i]) {
        f++;
      }
    }
    if (f == n) {
      if (s.size() == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  }
}
