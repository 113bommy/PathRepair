#include <bits/stdc++.h>
using namespace std;
set<long long int>::iterator it;
map<char, long long int>::iterator itm;
long long int removeDuplicates(long long int arr[], long long int n) {
  sort(arr, arr + n);
  if (n == 0 || n == 1) return n;
  long long int temp[n];
  long long int j = 0;
  for (long long int i = 0; i < n - 1; i++)
    if (arr[i] != arr[i + 1]) temp[j++] = arr[i];
  temp[j++] = arr[n - 1];
  for (long long int i = 0; i < j; i++) arr[i] = temp[i];
  return j;
}
long long int mostFrequent(long long int arr[], long long int n) {
  sort(arr, arr + n);
  long long int max_count = 1, res = arr[0], curr_count = 1;
  for (long long int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1])
      curr_count++;
    else {
      if (curr_count > max_count) {
        max_count = curr_count;
        res = arr[i - 1];
      }
      curr_count = 1;
    }
  }
  if (curr_count > max_count) {
    max_count = curr_count;
    res = arr[n - 1];
  }
  return res;
}
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
long long int gcd(long long int a, long long int b) {
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long int pow(long long int a, long long int b, long long int MOD) {
  long long int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > MOD) x %= MOD;
    }
    y = (y * y);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}
int main() {
  long long int t;
  t = 1;
  while (t--) {
    long long int n, m, i, l = 0, r = 0, ans = 0, j, k, x, y, z, c1 = 0,
                           sum = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0,
                           flag = 0, ind3 = -1, ind = -1, ind2 = -1;
    cin >> n;
    char a[n][n];
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < n; j++) cin >> a[i][j];
    }
    for (long long int i = 1; i < n - 1; i++) {
      for (long long int j = 1; j < n - 1; j++) {
        if (a[i][j] == 'X' && a[i + 1][j + 1] == 'X' &&
            a[i + 1][j - 1] == 'X' && a[i - 1][j - 1] == 'X' &&
            a[i - 1][j + 1] == 'X')
          c1++;
      }
    }
    cout << c1 << "\n";
  }
}
