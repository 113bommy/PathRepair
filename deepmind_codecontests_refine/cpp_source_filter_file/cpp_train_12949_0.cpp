#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int mi = 1000000000000;
  long long int a[20000];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
  }
  for (int i = 1; i <= n; i++)
    if (a[i] % mi == 1) {
      cout << -1;
      return 0;
    }
  cout << mi;
  return 0;
}
