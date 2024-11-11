#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  long long result = 0;
  cin >> n >> m >> k;
  vector<string> a(n);
  vector<int> starts(m, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int start;
  if (k > 1) {
    for (int i = 0; i < n; i++) {
      start = -1;
      for (int j = 0; j < m; j++) {
        if ((start == -1) && (a[i][j] == '.')) {
          start = j;
        }
        if ((starts[j] == -1) && (a[i][j] == '.')) {
          starts[j] = i;
        }
        if ((start != -1) && (a[i][j] == '*')) {
          int range = j - start;
          if (range >= k) {
            result += range - k + 1;
          }
          start = -1;
        }
        if ((starts[j] != -1) && (a[i][j] == '*')) {
          int range = i - starts[j];
          if (range >= k) {
            result += range - k + 1;
          }
          starts[j] = -1;
        }
      }
      if (start != -1) {
        int range = m - start;
        if (range >= k) {
          result += range - k + 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      if (starts[i] != -1) {
        int range = n - starts[i];
        if (range >= k) {
          result += range - k + 1;
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == '.') {
          result++;
        }
      }
    }
  }
  cout << result << endl;
  return 0;
}
