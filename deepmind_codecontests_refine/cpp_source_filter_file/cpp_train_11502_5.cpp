#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j, x, n, k, a, b, c, d, e, cnt = 0, temp, i1, i2, i3, i4, i5, i6, i7,
                                    i8, i9, sum = 0, t, mn, bal;
  cin >> n >> k;
  vector<int> v;
  for (i = 1; i <= n; i++) {
    v.push_back(i);
    for (j = 0; j <= n - i; j++) sum += i;
  }
  if (n == 2) {
    if (k == 1)
      cout << "1 2";
    else
      cout << "2 1";
    return 0;
  }
  for (i9 = 0; i9 < 9 && cnt < k; i9++) {
    for (i8 = 0; i8 < 8 && cnt < k; i8++) {
      for (i7 = 0; i7 < 7 && cnt < k; i7++) {
        for (i6 = 0; i6 < 6 && cnt < k; i6++) {
          for (a = 0; cnt < k && a < 5; a++) {
            for (b = 0; b < 4 && cnt < k; b++) {
              for (c = 0; c < 3 && cnt < k; c++) {
                for (d = 0; d < 2 && cnt < k; d++) {
                  for (e = 0; e < 1 && cnt < k; e++) {
                    t = 0;
                    vector<int> s;
                    s = v;
                    if (n > 8 && i9 != 0) {
                      for (j = 0; j < i9; j++) {
                        temp = s[n - (9 - i9) - j];
                        s[n - (9 - i9) - j] = s[n - (9 - i9) - j - 1];
                        s[n - (9 - i9) - j - 1] = temp;
                      }
                    }
                    if (n > 7 && i8 != 0) {
                      for (j = 0; j < i8; j++) {
                        temp = s[n - (8 - i8) - j];
                        s[n - (8 - i8) - j] = s[n - (8 - i8) - j - 1];
                        s[n - (8 - i8) - j - 1] = temp;
                      }
                    }
                    if (n > 6 && i7 != 0) {
                      for (j = 0; j < i7; j++) {
                        temp = s[n - (7 - i7) - j];
                        s[n - (7 - i7) - j] = s[n - (7 - i7) - j - 1];
                        s[n - (7 - i7) - j - 1] = temp;
                      }
                    }
                    if (n > 5 && i6 != 0) {
                      for (j = 0; j < i6; j++) {
                        temp = s[n - (6 - i6) - j];
                        s[n - (6 - i6) - j] = s[n - (6 - i6) - j - 1];
                        s[n - (6 - i6) - j - 1] = temp;
                      }
                    }
                    if (n > 4 && a != 0) {
                      for (j = 0; j < a; j++) {
                        temp = s[n - (5 - a) - j];
                        s[n - (5 - a) - j] = s[n - (5 - a) - j - 1];
                        s[n - (5 - a) - j - 1] = temp;
                      }
                    }
                    if (n > 3 && b != 0) {
                      for (j = 0; j < b; j++) {
                        temp = s[n - (4 - b) - j];
                        s[n - (4 - b) - j] = s[n - (4 - b) - j - 1];
                        s[n - (4 - b) - j - 1] = temp;
                      }
                    }
                    if (n > 2 && c != 0) {
                      for (j = 0; j < c; j++) {
                        temp = s[n - (3 - c) - j];
                        s[n - (3 - c) - j] = s[n - (3 - c) - j - 1];
                        s[n - (3 - c) - j - 1] = temp;
                      }
                    }
                    if (n > 2 && d != 0) {
                      for (j = 0; j < d; j++) {
                        temp = s[n - (2 - d) - j];
                        s[n - (2 - d) - j] = s[n - (2 - d) - j - 1];
                        s[n - (2 - d) - j - 1] = temp;
                      }
                    }
                    for (i = 0; i <= n - 1; i++) {
                      mn = n + 1;
                      for (j = i; j <= n; j++) {
                        mn = min(mn, s[j]);
                        t += mn;
                      }
                    }
                    if (cnt == k - 1 && t == sum) {
                      cout << s[0];
                      for (i = 1; i <= n - 1; i++) cout << " " << s[i];
                      return 0;
                    }
                    if (t == sum) cnt++;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
