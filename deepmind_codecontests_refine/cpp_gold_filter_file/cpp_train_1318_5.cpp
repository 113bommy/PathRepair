#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
  ios::sync_with_stdio(false);
  cin >> str;
  int n = str.size(), a, b;
  a = b = 0;
  for (int i = 0; i <= n - 1; i++) {
    if (str[i] == '-')
      a++;
    else
      b++;
  }
  if (b == 0 || a % b == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
