#include <bits/stdc++.h>
using namespace std;
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void pairsort(int a[], int b[], int n) {
  pair<int, int> pairt[n];
  for (int i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (int i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
void pairsortlli(long long int a[], long long int b[], long long int n) {
  pair<long long int, long long int> pairt[n];
  for (long long int i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  int j = n - 1;
  for (long long int i = 0; i < n; i++) {
    a[j] = pairt[i].first;
    b[j] = pairt[i].second;
    j--;
  }
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int bins(long long int arr[], long long int l, long long int r,
                   long long int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return bins(arr, l, mid - 1, x);
    return bins(arr, mid + 1, r, x);
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  long long int a[m], b[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    cin >> b[i];
  }
  long long int s = 0;
  pairsortlli(b, a, m);
  long long int i = 0;
  while (n > 0 && i < m) {
    if (a[i] <= n) {
      s += a[i] * b[i];
      n -= a[i];
    } else {
      s += b[i] * n;
      n = 0;
    }
    i++;
  }
  cout << s << "\n";
}
