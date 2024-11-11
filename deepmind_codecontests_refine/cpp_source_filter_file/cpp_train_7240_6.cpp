#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  a[n++] = 0;
  for (int i = 0; i < n; i++) {
    cout << (a[i] + a[i + 1]) << " ";
  }
  return 0;
}
