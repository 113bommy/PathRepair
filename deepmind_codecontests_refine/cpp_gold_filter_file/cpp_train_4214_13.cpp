#include <bits/stdc++.h>
using namespace std;
const int N = 500;
long long n, a[N], need, mid;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mid += a[i];
  }
  sort(a + 1, a + n + 1);
  if (n == 0) {
    cout << "YES\n1\n1\n3\n3";
  }
  if (n == 4) {
    if (mid % 4 == 0 && a[4] - a[1] == mid / 4 && (a[3] + a[2]) % 2 == 0 &&
        (a[3] + a[2]) / 2 == mid / 4) {
      cout << "YES";
      return 0;
    }
    cout << "NO";
    return 0;
  }
  if (n == 3) {
    for (int i = 1; i <= 400000; i++) {
      if ((mid + i) % 4) {
        continue;
      }
      if (i <= a[1]) {
        need = mid + i;
        need /= 4;
        if ((a[1] + a[2]) % 2 == 0 && (a[1] + a[2]) / 2 == need &&
            a[3] - i == need) {
          cout << "YES\n" << i;
          return 0;
        }
      } else if (i <= a[2]) {
        need = mid + i;
        need /= 4;
        if ((i + a[2]) % 2 == 0 && (i + a[2]) / 2 == need &&
            a[3] - a[1] == need) {
          cout << "YES\n" << i;
          return 0;
        }
      } else if (i <= a[3]) {
        need = mid + i;
        need /= 4;
        if ((i + a[2]) % 2 == 0 && (i + a[2]) / 2 == need &&
            a[3] - a[1] == need) {
          cout << "YES\n" << i;
          return 0;
        }
      }
      if (i >= a[3]) {
        need = mid + i;
        need /= 4;
        if ((a[3] + a[2]) % 2 == 0 && (a[3] + a[2]) / 2 == need &&
            i - a[1] == need) {
          cout << "YES\n" << i;
          return 0;
        }
      }
    }
    cout << "NO";
    return 0;
  }
  if (n == 2) {
    for (int i = 1; i <= 2000; i++) {
      for (int j = i; j <= 2000; j++) {
        if (i <= a[1]) {
          if ((mid + i + j) % 4) {
            continue;
          }
          need = mid + i + j;
          need /= 4;
          if (j <= a[1]) {
            if ((j + a[1]) % 2 == 0 && (a[1] + j) / 2 == need &&
                a[2] - i == need) {
              cout << "YES\n" << i << "\n" << j;
              return 0;
            }
          } else if (j <= a[2]) {
            if ((j + a[1]) % 2 == 0 && (j + a[1]) / 2 == need &&
                a[2] - i == need) {
              cout << "YES\n" << i << "\n" << j;
              return 0;
            }
          }
          if (j >= a[2]) {
            if ((a[1] + a[2]) % 2 == 0 && (a[1] + a[2]) / 2 == need &&
                j - i == need) {
              cout << "YES\n" << i << "\n" << j;
              return 0;
            }
          }
        } else if (i <= a[2]) {
          if ((mid + i + j) % 4) {
            continue;
          }
          need = mid + i + j;
          need /= 4;
          if (j <= a[2]) {
            if ((j + i) % 2 == 0 && (i + j) / 2 == need &&
                a[2] - a[1] == need) {
              cout << "YES\n" << i << "\n" << j;
              return 0;
            }
          }
          if (j >= a[2]) {
            if ((i + a[2]) % 2 == 0 && (i + a[2]) / 2 == need &&
                j - a[1] == need) {
              cout << "YES\n" << i << "\n" << j;
              return 0;
            }
          }
        }
        if (i >= a[2]) {
          if ((mid + i + j) % 4) {
            continue;
          }
          need = mid + i + j;
          need /= 4;
          if (j >= a[2]) {
            if ((i + a[2]) % 2 == 0 && (i + a[2]) / 2 == need &&
                j - a[1] == need) {
              cout << "YES\n" << i << "\n" << j;
              return 0;
            }
          }
        }
      }
    }
    cout << "NO";
    return 0;
  }
  if (n == 1) {
    for (int k = a[1] + 1; k <= 1000; k++) {
      for (int i = 1; i <= k; i++) {
        int j = max((k - a[1]) * 2ll, i * 1ll) - min((k - a[1]) * 2ll, i * 1ll);
        if (j > k) {
          continue;
        }
        need = a[1] + i + j + k;
        if (need % 4) {
          ++i;
          continue;
        }
        need /= 4;
        if ((i + j) % 2 == 0 && k - a[1] == need) {
          cout << "YES\n" << i << "\n" << j << "\n" << k;
          return 0;
        }
      }
    }
    for (int k = a[1] + 1; k <= 1000; k++) {
      for (int i = 1; i <= k; i++) {
        int j = max((k - i) * 2ll, a[1] * 1ll) - min((k - i) * 2ll, a[1] * 1ll);
        need = a[1] + i + j + k;
        if (need % 4) {
          continue;
        }
        need /= 4;
        if ((a[1] + max(j, i)) % 2 == 0 && k - min(i, j) == need) {
          cout << "YES\n" << min(i, j) << "\n" << max(i, j) << "\n" << k;
          return 0;
        }
      }
    }
    for (int k = 1; k <= a[1]; k++) {
      for (int i = 1; i <= k; i++) {
        int j = max((a[1] - i) * 2ll, k * 1ll) - min((a[1] - i) * 2ll, k * 1ll);
        need = a[1] + i + j + k;
        if (need % 4) {
          continue;
        }
        need /= 4;
        if (i > j) {
          swap(i, j);
        }
        if ((k + max(j, i)) % 2 == 0 && a[1] - min(i, j) == need) {
          cout << "YES\n" << min(i, j) << "\n" << max(i, j) << "\n" << k;
          return 0;
        }
      }
    }
  }
  return 0;
}
