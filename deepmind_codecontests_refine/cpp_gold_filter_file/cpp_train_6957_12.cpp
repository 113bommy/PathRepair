#include <bits/stdc++.h>
using namespace std;
int main () {
  string a, b;
  cin >> a >> b;
  int x = stoi(a + b);
  int ans = (int)sqrt(x);
  if (ans * ans == x) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
