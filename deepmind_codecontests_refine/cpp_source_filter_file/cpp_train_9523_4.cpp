#include <bits/stdc++.h>
using namespace std;
int* rec(int n, long long int m) {
  int* a = new int[n];
  if (n == 1) {
    a[0] = 1;
  } else {
    int* temp;
    if (m % 2 == 1) {
      temp = rec(n - 1, (m + 1) / 2);
      int x;
      for (int i = 0; i < n - 1; i++) {
        if (temp[i] == n - 1) {
          x = i;
          break;
        }
      }
      long long int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (i == x + 1) {
          a[i] = n;
          continue;
        } else {
          a[i] = temp[cnt];
          cnt++;
        }
      }
    } else {
      temp = rec(n - 1, m / 2);
      int x;
      for (int i = 0; i < n - 1; i++) {
        if (temp[i] == n - 1) {
          x = i;
          break;
        }
      }
      long long int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (i == x) {
          a[i] = n;
          continue;
        } else {
          a[i] = temp[cnt];
          cnt++;
        }
      }
    }
  }
  return a;
}
int main() {
  long long int t = 10;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    int* a = rec(n, m);
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
