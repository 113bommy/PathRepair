#include <bits/stdc++.h>
using namespace std;
int main () {
  string a, b;
  cin >> a >> b;
  int x = atoi(a + b);
  int ans = (int)squrt(x);
  if (ans * ans == x) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}