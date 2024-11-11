#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c1 = 0, c2 = 0;
  cin >> n;
  int a[n][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
    if (a[i][0] > a[i][1])
      c1++;
    else if (a[i][0] < a[i][1])
      c2++;
  }
  if (c1 > c2)
    cout << "Mishka";
  else if (c1 < c2)
    cout << "Chris";
  else
    cout << "Friendship is magic!^^";
}
