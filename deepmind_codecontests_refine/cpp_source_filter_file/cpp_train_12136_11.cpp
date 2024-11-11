#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  string a;
  cin >> a;
  for (i = a.size() - 2; i > -1; i -= 2) cout << a[i];
  for (i = 0 & (a.size() - 1); i < n; i += 2) cout << a[i];
  cout << endl;
  return 0;
}
