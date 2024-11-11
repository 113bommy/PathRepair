#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t, n, i, j, x;
  int n1, n2;
  int a, b, p, q;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n;
    n1 = 0, n2 = 0;
    vector<int> v, v1, v2;
    vector<int> even, odd;
    for (j = 0; j < n; j++) {
      cin >> x;
      if (x % 2) {
        n1++;
        odd.push_back(j);
      } else {
        n2++;
        even.push_back(j);
      }
      v.push_back(x);
      v1.push_back(x);
      v2.push_back(x);
    }
    long long max1 = 0, max2 = 0, max_total;
    int k, temp;
    a = 0, b = 0;
    if (n % 2) {
      if (abs(n1 - n2) != 1) {
        cout << "-1\n";
      } else {
        if (n1 < n2) {
          for (k = 0; k < n; k++) {
            if (k % 2) {
              while (a < n && !(v1[a] % 2)) {
                a++;
              }
              max1 += abs(a - k);
              if (a != k) {
                temp = v1[a];
                v1[a] = v1[k];
                v1[k] = temp;
              }
              a++;
            } else {
              while (b < n && v1[b] % 2) {
                b++;
              }
              max1 += abs(b - k);
              if (b != k) {
                temp = v1[b];
                v1[b] = v1[k];
                v1[k] = temp;
              }
              b++;
            }
          }
          cout << max1 << "\n";
        } else {
          for (k = 0; k < n; k++) {
            if (!(k % 2)) {
              while (a < n && !(v2[a] % 2)) {
                a++;
              }
              max2 += abs(a - k);
              if (a != k) {
                temp = v2[a];
                v2[a] = v2[k];
                v2[k] = temp;
              }
              a++;
            } else {
              while (b < n && v2[b] % 2) {
                b++;
              }
              max2 += abs(b - k);
              if (b != k) {
                temp = v2[b];
                v2[b] = v2[k];
                v2[k] = temp;
              }
              b++;
            }
          }
          cout << max2 << "\n";
        }
      }
    } else {
      if (n1 != n2) {
        cout << "-1\n";
      } else {
        a = 0, b = 0;
        for (k = 0; k < n; k++) {
          if (k % 2) {
            while (a < n && !(v1[a] % 2)) {
              a++;
            }
            max1 += abs(a - k);
            if (a != k) {
              temp = v1[a];
              v1[a] = v1[k];
              v1[k] = temp;
            }
            a++;
          } else {
            while (b < n && v1[b] % 2) {
              b++;
            }
            max1 += abs(b - k);
            if (b != k) {
              temp = v1[b];
              v1[b] = v1[k];
              v1[k] = temp;
            }
            b++;
          }
        }
        a = 0, b = 0;
        for (k = 0; k < n; k++) {
          if (!(k % 2)) {
            while (a < n && !(v2[a] % 2)) {
              a++;
            }
            max2 += abs(a - k);
            if (a != k) {
              temp = v2[a];
              v2[a] = v2[k];
              v2[k] = temp;
            }
            a++;
          } else {
            while (b < n && v2[b] % 2) {
              b++;
            }
            max2 += abs(b - k);
            if (b != k) {
              temp = v2[b];
              v2[b] = v2[k];
              v2[k] = temp;
            }
            b++;
          }
        }
        cout << min(max1, max2) << "\n";
      }
    }
  }
  return 0;
}
