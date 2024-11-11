#include <bits/stdc++.h>
using namespace std;
int const N = 200001;
int main() {
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  if (n != m || (n == 1 && a != b)) return puts("NO"), 0;
  bool ok = false;
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '1') ++x;
    if (b[i] == '1') ++y;
  }
  if ((!x || !y)) ok = false;
  if (a == b) ok = true;
  if (ok)
    puts("YES");
  else
    puts("NO");
}
