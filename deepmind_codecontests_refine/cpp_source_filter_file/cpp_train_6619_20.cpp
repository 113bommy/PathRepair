#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int n, l, pas = 0, x = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l;
    if (a[l] == 1)
      x--;
    else {
      x++;
      a[l] = 1;
    }
    if (x > pas) pas = x;
  }
  cout << pas;
  return 0;
}
