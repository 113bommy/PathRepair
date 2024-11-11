#include <bits/stdc++.h>
using namespace std;
int arr[8];
int n;
char q[] = {'A', 'B', 'C'};
bool canForm(int a, int b, int c, int d, int x, int y, int w) {
  if (y == 0) return false;
  int ar[4];
  ar[0] = a;
  ar[1] = b;
  ar[2] = c;
  ar[3] = d;
  for (int i = 0; i < 2; i++)
    for (int j = 2; j < 4; j++) {
      if (ar[i] == ar[j] && (ar[i] == y || ar[i] == n)) {
        int ans = 0, t, r;
        if (j == 2)
          ans += ar[3], t = ar[3];
        else
          ans += ar[2], t = ar[2];
        ans += ar[(i + 1) % 2];
        r = ar[(i + 1) % 2];
        if (ans == n) {
          cout << n << endl;
          for (int zz = 0; zz < y; zz++) {
            for (int xx = 0; xx < n; xx++)
              if (xx < t)
                cout << q[(w + 1) % 3];
              else
                cout << q[(w + 2) % 3];
            cout << endl;
          }
          return true;
        }
        if (ans == y) {
          cout << n << endl;
          for (int ee = 0; ee < r; ee++) {
            for (int xx = 0; xx < n; xx++) cout << q[(w + 1) % 3];
            cout << endl;
          }
          for (int ee = 0; ee < t; ee++) {
            for (int xx = 0; xx < n; xx++) cout << q[(w + 2) % 3];
            cout << endl;
          }
          return true;
        }
      }
    }
  return false;
}
int main() {
  int sum = 0;
  for (int i = 0; i < 6; i += 2) {
    cin >> arr[i] >> arr[i + 1];
    sum += arr[i] * arr[i + 1];
    n = max(n, max(arr[i + 1], arr[i]));
  }
  if (sum != n * n) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < 6; i += 2) {
    if (arr[i] == n) {
      if (canForm(arr[(i + 2) % 6], arr[(i + 3) % 6], arr[(i + 4) % 6],
                  arr[(i + 5) % 6], n, n - arr[i + 1], i / 2)) {
        for (int c = 0; c < arr[i + 1]; c++) {
          for (int v = 0; v < n; v++) cout << q[i / 2];
          cout << endl;
        }
        return 0;
      }
    }
    if (arr[i + 1] == n) {
      if (canForm(arr[(i + 2) % 6], arr[(i + 3) % 6], arr[(i + 4) % 6],
                  arr[(i + 5) % 6], n, n - arr[i], i / 2)) {
        for (int c = 0; c < arr[i]; c++) {
          for (int v = 0; v < n; v++) cout << q[i / 2];
          cout << endl;
        }
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
