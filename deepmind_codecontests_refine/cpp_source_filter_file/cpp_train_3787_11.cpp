#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  char a[55];
  cin >> n >> t;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int l = 1; l <= t; l++)
    for (int i = n; i >= 1; i--)
      if (a[i - 1] == 'B' && a[i] == 'G') swap(a[i - 1], a[i]);
  for (int i = 1; i <= n; i++) cout << a[i];
  cout << endl;
  return 0;
}
