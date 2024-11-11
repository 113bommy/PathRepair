#include <bits/stdc++.h>
using namespace std;
void run() {
  long long n;
  cin >> n;
  long long a, b;
  cin >> a >> b;
  if (a == 1 || b == 1) {
    long long yo[n][n];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        yo[i][j] = 0;
      }
    }
    if (a == 1 && b == 1 && (n == 2 || n == 3)) {
      cout << "NO" << endl;
      return;
    }
    if (a == 1 && b == 1 && n == 1) {
      cout << "YES" << endl;
      cout << 0;
      return;
    }
    if (a == 1 && b == 1) {
      cout << "YES" << endl;
      for (long long i = 0; i < n - 1; i++) {
        yo[i][i + 1] = 1;
        yo[i + 1][1] = 1;
      }
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
          cout << yo[i][j];
        }
        cout << endl;
      }
      return;
    }
    if (b == 1) {
      for (long long j = 1; j <= n - a; j++) {
        yo[j][0] = 1;
        yo[0][j] = 1;
      }
    } else {
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
          if (i != j) yo[i][j] = 1;
        }
      }
      for (long long j = 1; j <= n - b; j++) {
        yo[j][0] = 0;
        yo[0][j] = 0;
      }
    }
    cout << "YES" << endl;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        cout << yo[i][j];
      }
      cout << endl;
    }
  } else
    cout << "NO" << endl;
}
int main() {
  long long t = 1;
  for (long long i = 0; i < t; i++) {
    run();
  }
  return 0;
}
