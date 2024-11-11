#include <bits/stdc++.h>
using namespace std;
int n;
int a[105];
int main() {
  int k;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i < n; i++) {
    if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
      k++;
      a[i + 1] = 0;
    }
  }
  cout << k;
  return 0;
}
