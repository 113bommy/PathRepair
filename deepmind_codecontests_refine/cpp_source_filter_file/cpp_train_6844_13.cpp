#include <bits/stdc++.h>
long long int min(long long int a, long long int b, long long int c) {
  long long int min;
  min = (a > b) ? ((b > c) ? c : b) : ((a > c) ? c : a);
  return min;
}
long long int max(long long int a, long long int b, long long int c) {
  long long int max;
  max = (a < b) ? ((b < c) ? c : b) : ((a < c) ? c : a);
  return max;
}
int fac(int n) {
  if (n == 1 || n == 0) {
    return 1;
  } else
    return n * fac(n - 1);
}
int sum(int n) {
  if (n == 1)
    return 1;
  else if (n == 0)
    return 0;
  else
    return n + sum(n - 1);
}
void swap(int a, int b) {
  int c = a;
  a = b;
  b = c;
}
int gcd(int a, int b) {
  if (b > a) swap(a, b);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int c = 0;
  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int j = 0; j < i - 1; j++) {
      if (arr[i] == arr[j]) {
        flag = false;
        break;
      }
    }
    if (flag) c++;
  }
  if (k > c)
    cout << "NO\n";
  else {
    cout << "YES\n";
    int c = 0;
    for (int i = 0; i < n; i++) {
      bool flag = true;
      for (int j = 0; j <= i - 1; j++) {
        if (arr[i] == arr[j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << i + 1 << " ";
        c++;
      }
      if (c == k) break;
    }
    cout << endl;
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
