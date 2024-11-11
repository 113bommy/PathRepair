#include <bits/stdc++.h>
using namespace std;
long long mulmod(long long a, long long b, long long c) {
  long long x = 0, y = a % c;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x + y) % c;
    }
    y = (y * 2) % c;
    b /= 2;
  }
  return x % c;
}
long long modulo(long long a, long long b, long long c) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = mulmod(x, y, c);
    }
    y = mulmod(y, y, c);
    b /= 2;
  }
  return x % c;
}
bool Miller(long long p, int iteration) {
  if (p < 2) {
    return false;
  }
  if (p != 2 && p % 2 == 0) {
    return false;
  }
  long long s = p - 1;
  while (s % 2 == 0) {
    s /= 2;
  }
  for (int i = 0; i < iteration; i++) {
    long long a = rand() % (p - 1) + 1, temp = s;
    long long mod = modulo(a, temp, p);
    while (temp != p - 1 && mod != 1 && mod != p - 1) {
      mod = mulmod(mod, mod, p);
      temp *= 2;
    }
    if (mod != p - 1 && temp % 2 == 0) {
      return false;
    }
  }
  return true;
}
int length;
int binsearch(int arr[], int key) {
  int low = 0, mid, high = length - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] >= key)
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (arr[low] == key)
    return low;
  else
    return -1;
}
int main() {
  int n, m;
  cin >> n >> m;
  if (m > 2 * n + 2)
    cout << "-1" << endl;
  else if (n > m + 1)
    cout << "-1" << endl;
  else if (n == m)
    for (int i = 0; i < n; i++) cout << "10";
  else if (n == m + 1) {
    for (int i = 0; i < n; i++) cout << "01";
    cout << "0";
  } else {
    for (; n != 0 && m != n; m--, m--, n--) cout << "110";
    if (n != 0)
      for (int i = 0; i < n; i++) cout << "10";
    if (n == 0)
      for (int i = 0; i < m; i++) cout << "1";
  }
  return 0;
}
