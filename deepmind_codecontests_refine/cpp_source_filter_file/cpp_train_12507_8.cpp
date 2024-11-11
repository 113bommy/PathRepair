#include <bits/stdc++.h>
using namespace std;
int cd, a[1000], b[10000], ok, n;
int main() {
  cin >> cd;
  for (int i = 1; i <= cd; i++) cin >> a[i] >> b[i];
  cin >> n;
  for (int i = 1; i <= cd; i++)
    if (n >= b[i]) ok++;
  cout << cd - ok;
}
