#include <bits/stdc++.h>
using namespace std;
int a[300000];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= (n + 1) / 2; i++) {
    if (i % 2) swap(a[i], a[n - i + 1]);
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
