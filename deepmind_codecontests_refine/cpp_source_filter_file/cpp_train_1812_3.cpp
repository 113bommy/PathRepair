#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  long m;
  long k;
  cin >> n >> m >> k;
  vector<string> a = {};
  for (long i = 0; i < n; i++) {
    string a1;
    cin >> a1;
    a.push_back(a1);
  }
  long long b = 0;
  for (long l = 1; l < (min(n, m) - 1) / 2; l++) {
    for (long i = l; i < n - l; i++) {
      for (long j = l; j < m - l; j++) {
        if (a[i][j] == '*') {
          if (a[i + l][j] == '*') {
            if (a[i - l][j] == '*') {
              if (a[i][j + l] == '*') {
                if (a[i][j - l] == '*') {
                  b++;
                  if (b == k) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                    cout << i + 1 - l << ' ' << j + 1 << endl;
                    cout << i + 1 + l << ' ' << j + 1 << endl;
                    cout << i + 1 << ' ' << j + 1 - l << endl;
                    cout << i + 1 << ' ' << j + 1 + l;
                    break;
                  }
                }
              }
            }
          }
        }
      }
      if (b == k) {
        break;
      }
    }
    if (b == k) {
      break;
    }
  }
  if (b < k) {
    cout << -1;
  }
}
