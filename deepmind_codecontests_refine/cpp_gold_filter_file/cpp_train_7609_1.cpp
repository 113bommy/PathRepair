#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int i;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int stole = 0;
  for (i = 0; i < n - 1; i++) {
    if (a[i + 1] != a[i] + 1) stole += a[i + 1] - a[i] - 1;
  }
  cout << stole;
}
