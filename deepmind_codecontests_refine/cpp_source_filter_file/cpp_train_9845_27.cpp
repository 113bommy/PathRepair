#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string a;
  cin >> n >> a;
  int l(0);
  int m(0);
  for (int i = 0; i < n; i++) {
    if (a[i] == 'A')
      l++;
    else if (a[i] == 'D')
      m++;
  }
  if (l > m)
    cout << "Anton";
  else if (l < m)
    cout << "Danik";
  else if (l == m)
    cout << "Frinendship";
  return 0;
}
