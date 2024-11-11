#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0, y = 0;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 'L')
      x++;
    else
      y++;
  }
  cout << x + y + 1;
}
