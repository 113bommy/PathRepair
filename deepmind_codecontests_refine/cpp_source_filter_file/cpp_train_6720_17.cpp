#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mn, cn;
  int countm = 0, countc = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> mn;
    cin >> cn;
    if (mn > cn)
      countm++;
    else if (mn < cn)
      countc++;
  }
  if (countm > countc)
    cout << 'Mishka';
  else if (countm < countc)
    cout << 'Chris';
  else
    cout << 'Friendship is magic!^^';
}
