#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c = "";
  cin >> a >> b;
  long long checker = 0;
  c += a[0];
  for (int i = 1; i < a.size(); i++) {
    if (a[i] < a[i - 1])
      c += a[i];
    else
      break;
  }
  c += b[0];
  cout << c;
  return 0;
}
