#include <bits/stdc++.h>
using namespace std;
int n;
int a, b, c;
int ar[1000000];
int acc[1000000];
int f[1000000];
int wb[1000000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  acc[0] = ar[0];
  wb[0] = 0;
  f[ar[0]] = -1;
  for (int i = 1; i <= n; i++) {
    if (i == n || ar[i] > acc[i - 1]) {
      int as = 0;
      for (int j = wb[i - 1] + 1; j < i; j++) {
        if ((ar[j] < as))
          continue;
        else {
          as = ar[j];
          if (wb[i - 1] == 0 || acc[wb[i - 1] - 1] < ar[j]) {
            f[acc[i - 1]]++;
          }
        }
      }
      if (i != n) {
        acc[i] = ar[i];
        wb[i] = i;
        f[ar[i]]--;
      }
    } else {
      acc[i] = acc[i - 1];
      wb[i] = wb[i - 1];
    }
  }
  int ma = f[1], mi = 1;
  for (int i = 2; i <= n; i++) {
    if (ma < f[i]) {
      mi = i;
      ma = f[i];
    }
  }
  cout << mi;
  return 0;
}
