#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, t = 0, i;
  cin >> n >> d;
  int a[1001];
  for (i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        if (d >= abs(a[i] - a[j])) t++;
      }
    }
  }
  cout << t;
}
