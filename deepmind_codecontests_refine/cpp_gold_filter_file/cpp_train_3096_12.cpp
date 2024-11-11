#include <bits/stdc++.h>
using namespace std;
int arr[1005][1005];
void f1(long long n, long long c, bool rev) {
  if (c == 0) {
    for (long long i = 1; i < n; i++) arr[i][i + 1] = arr[i + 1][i] = 1;
  } else {
    for (long long j = 1; j < 1 + c; j++)
      for (long long i = j + 1; i < n + 1; i++) {
        arr[j][i] = 1;
        arr[i][j] = 1;
      }
  }
  if (!rev) {
    for (long long i = 1; i < n + 1; i++) {
      for (long long j = 1; j < n + 1; j++) cout << arr[i][j];
      cout << '\n';
    }
  } else {
    for (long long i = 1; i < n + 1; i++) {
      for (long long j = 1; j < n + 1; j++) {
        if (i == j)
          cout << 0;
        else
          cout << (1 - arr[i][j]);
      }
      cout << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    int n, a, b;
    cin >> n >> a >> b;
    if ((a != 1) && (b != 1)) {
      cout << "NO";
      return 0;
    }
    if ((n == 2) && (a == 1) && (b == 1)) {
      cout << "NO";
      return 0;
    }
    if ((n == 3) && (a == b)) {
      cout << "NO";
      return 0;
    }
    cout << "YES\n";
    if (n == 1)
      cout << 0;
    else if (n == 2) {
      if (a == 1)
        cout << "01\n10";
      else
        cout << "00\n00";
    } else if ((n == 3) && (a == 1) && (b == 2))
      f1(n, 0, false);
    else if ((n == 3) && (a == 2) && (b == 1))
      f1(n, 0, true);
    else if ((n == 3) && (a == 1) && (b == 3))
      f1(n, 2, false);
    else if ((n == 3) && (a == 3) && (b == 1))
      f1(n, 2, true);
    else {
      if (a == b)
        f1(n, 0, false);
      else if (a > b)
        f1(n, a - 1, true);
      else
        f1(n, b - 1, false);
    }
  }
  return 0;
}
