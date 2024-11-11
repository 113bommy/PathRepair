#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  int b[10001] = {};
  int max = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > max) max = a[i];
  }
  cout << max << " ";
  int nmax = 1;
  for (int i = 1; i <= n; i++) {
    if (max % a[i] == 0 && b[a[i]] != 1) {
      b[a[i]] = 1;
      continue;
    }
    if (a[i] > nmax) nmax = a[i];
  }
  cout << nmax << endl;
}
