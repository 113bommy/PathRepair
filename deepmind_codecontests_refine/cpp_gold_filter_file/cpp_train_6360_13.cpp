#include <bits/stdc++.h>
using namespace std;
long long a = 0, b = 0, c = 0, d = 0;
int main() {
  int n;
  cin >> n;
  string e, f;
  cin >> e >> f;
  for (int i = 0; i < n; i++) {
    if (e[i] == '0' && f[i] == '0')
      a++;
    else if (e[i] == '0' && f[i] == '1')
      b++;
    else if (e[i] == '1' && f[i] == '0')
      c++;
    else if (e[i] == '1' && f[i] == '1')
      d++;
  }
  long long res = a * (c + d) + b * c;
  cout << res << endl;
  return 0;
}
