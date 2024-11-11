#include <bits/stdc++.h>
using namespace std;
const int limit = 1e7 + 1;
const int inf = 1e7;
const int mod = 1e9 + 7;
vector<bool> sieve(int n) {
  vector<bool> prime(n, 1);
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = 0;
      }
    }
  }
  return prime;
}
int bs(int x, int a[], int n) {
  int l = 0;
  int h = n - 1;
  int ans = -1;
  while (l <= h) {
    int mid = l + (h - l) / 2;
    if (a[mid] == x) {
      return mid;
    } else if (a[mid] < x) {
      l = mid + 1;
    } else {
      ans = mid;
      h = mid - 1;
    }
  }
  return ans;
}
long long int nCr(long long int n, long long int r) {
  if (n < r) {
    return 0;
  }
  long long int ans = 1;
  for (int i = 1; i <= r; i++) {
    ans = ans * (n - i + 1) / i;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int count = 0;
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '+') {
      count++;
    } else {
      count--;
    }
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == '+') {
      count--;
    } else if (b[i] == '-') {
      count++;
    } else {
      t++;
    }
  }
  if (t) {
    int q = (t + count) / 2;
    long double ans = nCr(t, q) / pow(2, t);
    cout << setprecision(9) << ans << "\n";
  } else {
    if (count) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return 0;
}
