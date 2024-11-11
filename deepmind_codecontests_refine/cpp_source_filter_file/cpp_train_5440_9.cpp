#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b) {
    return a;
  }
  return b;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long int min(long long int a, long long int b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long int power(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      res = (res * x);
    }
    x = (x * x);
    n = n / 2;
  }
  return res;
}
long long int factorialNumInverse[1000001];
long long int naturalNumInverse[1000001];
long long int fact[1000001];
void InverseofNumber(long long int n, long long int p) {
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (long long int i = 2; i <= n; i++)
    naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(long long int n, long long int p) {
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
  for (long long int i = 2; i <= n; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(long long int n, long long int p) {
  fact[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
long long int nCrModp(long long int n, long long int r, long long int p) {
  long long int ans =
      ((fact[n] * factorialNumInverse[r]) % p * factorialNumInverse[n - r]) % p;
  return ans;
}
long long int n, p;
vector<long long int> arr;
bool check(long long int x) {
  long long int res = 1;
  for (long long int i = 0; i < n; i++) {
    long long int d =
        upper_bound(arr.begin(), arr.end(), x + i) - arr.begin() - i;
    if (d % p == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  factorial(200005, 1000000007);
  InverseofNumber(200005, 1000000007);
  InverseofFactorial(200005, 1000000007);
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    arr.push_back(x);
  }
  sort(arr.begin(), arr.end());
  long long int l = LONG_MIN;
  for (int i = 0; i < n; i++) {
    l = max(l, arr[i] - i);
  }
  long long int h = *max_element(arr.begin(), arr.end()) - 1;
  for (int i = 0; i < n; i++) {
    if (i + p - 1 < n) {
      h = min(h, arr[i + p - 1] - i);
    }
  }
  cout << max(0, (h - l)) << "\n";
  for (int i = l; i < h; i++) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
