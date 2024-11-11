#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(k);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) cin >> b[i];
  sort(b.begin(), b.end());
  int c;
  int start = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (i == 0) {
        if (a[i + 1] == 0) {
          cout << "Yes\n";
          return 0;
        } else {
          for (c = start; c < k; c++)
            if (b[c] > a[i + 1]) break;
          if (c != k) {
            cout << "Yes\n";
            return 0;
          }
          a[i] = b[start];
          start++;
        }
      } else if (i == n - 1) {
        if (b[k - 1] < a[n - 2]) {
          cout << "Yes\n";
          return 0;
        }
        a[i] = b[start];
        start++;
      } else {
        if (a[i + 1] == 0) {
          cout << "Yes\n";
          return 0;
        } else {
          if (a[i - 1] > a[i + 1]) {
            cout << "Yes\n";
            return 0;
          }
          for (c = start; c < k; c++) {
            if (b[c] < a[i - 1]) {
              cout << "Yes\n";
              return 0;
            }
            if (b[c] > a[i - 1]) break;
          }
          for (c = start; c < k; c++) {
            if (b[c] > a[i + 1]) {
              cout << "Yes\n";
              return 0;
            }
          }
          a[i] = b[start];
          start++;
        }
      }
    } else {
      if (i == 0) {
        if (a[i + 1] != 0 && a[i + 1] < a[i]) {
          cout << "Yes\n";
          return 0;
        }
      } else {
        if (a[i] < a[i + 1]) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}
