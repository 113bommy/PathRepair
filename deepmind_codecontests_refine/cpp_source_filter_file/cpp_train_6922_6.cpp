#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
bool isPalindrome(string s) {
  int l = 0;
  int h = s.size() - 1;
  while (h > l) {
    if (s[l++] != s[h--]) {
      return false;
    }
  }
  return true;
}
int ternarySearch(int l, int r, int key, int ar[]) {
  while (r >= l) {
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;
    if (ar[mid1] == key) {
      return mid1;
    }
    if (ar[mid2] == key) {
      return mid2;
    }
    if (key < ar[mid1]) {
      r = mid1 - 1;
    } else if (key > ar[mid2]) {
      l = mid2 + 1;
    } else {
      l = mid1 + 1;
      r = mid2 - 1;
    }
  }
  return -1;
}
int binarySearch(int arr[], int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x) return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  int k, x;
  cin >> n >> m;
  cin >> k >> x;
  long long a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  if (a[k] < b[n]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
