#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  int chet = 0;
  int nechet = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
    if (a[i] % 2 == 0) {
      chet++;
    } else {
      nechet++;
    }
  }
  if (n != k) {
    if ((n - k) % 2 == 0) {
      if (k % 2 != 0) {
        if ((n - k) / 2 >= chet) {
          cout << "Stannis";
        } else {
          cout << "Daenerys";
        }
      } else {
        cout << "Daenerys";
      }
    } else {
      if (k % 2 == 0) {
        if ((n - k) / 2 >= nechet || (n - k) / 2 >= chet) {
          cout << "Daenerys";
        } else {
          cout << "Stannis";
        }
      } else {
        if ((n - k) / 2 >= nechet) {
          cout << "Daenerys";
        } else {
          cout << "Stannis";
        }
      }
    }
  } else {
    if (n % 2 == 0) {
      cout << "Daenerys";
    } else {
      cout << "Stannis";
    }
  }
  return 0;
}
