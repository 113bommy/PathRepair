#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  int x, sum2 = 0;
  char s1 = '(', s2 = ')';
  string temp;
  for (int i = 0; i < t; i++) {
    cin >> n;
    string sum[2 * n];
    if (n >= 1) {
      for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
          sum[i] = s1;
        }
        for (int i = n; i < 2 * n; i++) {
          sum[i] = s2;
        }
      }
      do {
        for (int i = 0; i < 2 * n; i++) {
          cout << sum[i];
        }
        sum2 += 1;
        for (int i = n - 1; i >= 0; i--) {
          for (int j = n; j < 2 * n; j++) {
            temp = sum[i];
            sum[i] = sum[j];
            sum[j] = temp;
            break;
          }
        }
        cout << endl;
      } while (sum2 < n);
    }
    sum2 = 0;
  }
  return 0;
}
