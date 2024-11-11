#include <bits/stdc++.h>
using namespace std;
int a[111111];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  bool f = 0;
  for (int i = 1; i <= n - 2; i++) {
    if (a[i] + a[i + 1] >= a[i + 2]) f = 1;
  }
  if (f)
    cout << "YES";
  else
    cout << "NO";
}
