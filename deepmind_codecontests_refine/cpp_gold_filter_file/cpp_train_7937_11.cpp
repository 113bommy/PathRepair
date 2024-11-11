#include <bits/stdc++.h>
using namespace std;
long long int power(long long int b, long long int e, long long int m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long int power(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    int f = 0;
    int c = 0;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      if (arr[i] == i) {
        arr[i] = -1;
        c++;
      }
    }
    int d = 0;
    if (arr[1] == -1) {
      f = 2;
      for (int i = 1; i <= c; i++) {
        if (arr[i] != -1) {
          f = 1;
          break;
        } else {
          d++;
          arr[i] = -2;
        }
      }
    }
    if (arr[n] == -1) {
      f = 2;
      for (int i = n; i >= n - c + 1; i--) {
        if (arr[i] != -1) {
          f = 1;
          break;
        } else {
          d++;
        }
      }
    }
    if (d == c) f = 3;
    if (c == n)
      cout << "0"
           << "\n";
    else if (c == 0)
      cout << "1"
           << "\n";
    else if (f == 2 || f == 3)
      cout << "1"
           << "\n";
    else
      cout << "2"
           << "\n";
  }
  return 0;
}
