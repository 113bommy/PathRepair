#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0, n;
  cin >> n;
  string a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    if (a[i] == "++x" || a[i] == "x++") x++;
  for (int i = 0; i < n; i++)
    if (a[i] == "--x" || a[i] == "x--") x--;
  cout << x;
  return 0;
}
