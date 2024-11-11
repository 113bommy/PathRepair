#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, div = 0, d, s;
  cin >> n >> m;
  div = n / m;
  s = div + 1;
  if (m % n == 0)
    for (int i = 0; i < m; i++) cout << div << " ";
  else {
    d = n - (m * div);
    for (int i = 0; i < m; i++) {
      if (i >= d)
        cout << div << " ";
      else if (i < d)
        cout << s << " ";
    }
  }
  return 0;
}
