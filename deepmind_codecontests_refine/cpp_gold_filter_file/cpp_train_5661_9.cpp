#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, l = 0;
  string a;
  cin >> a;
  for (i = 0; i < a.length(); i++) {
    if (a[i] == '0') {
      l = 1;
      a.erase(a.begin() + i);
      break;
    }
  }
  if (l == 0) a.erase(a.begin());
  cout << a;
  return 0;
}
