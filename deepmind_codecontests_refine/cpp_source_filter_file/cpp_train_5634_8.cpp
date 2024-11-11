#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<string> s(n);
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    for (long long j = 0; j < m; j++) {
      cnt += s[i][j] == '#';
    }
  }
  char u[1000][1000] = {0};
  for (long long i = 1; i < n - 1; i++) {
    for (long long j = 1; j < m - 1; j++) {
      long long c = 0;
      for (long long k = i - 1; k <= i + 1; k++) {
        for (long long k1 = j - 1; k1 <= j + 1; k1++) {
          if (k == k1 && k == i) {
            continue;
          }
          if (s[k][k1] == '#') {
            c++;
          }
        }
      }
      if (c != 8) {
        continue;
      }
      for (long long k = i - 1; k <= i + 1; k++) {
        for (long long k1 = j - 1; k1 <= j + 1; k1++) {
          if (k == k1 && k == i) {
            continue;
          }
          if (s[k][k1] == '#' && u[k][k1] != 1) {
            cnt--;
            u[k][k1] = 1;
          }
        }
      }
    }
  }
  if (cnt == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
