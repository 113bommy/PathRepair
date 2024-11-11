#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 3 && n >= 4)
    cout << -1 << endl;
  else {
    if (m == 3 && n == 4)
      puts("-1 0\n1 0\n0 2\n0 1");
    else {
      for (int i = 1; i <= m; i++) cout << i << " " << i * i + 343231 << endl;
      n -= m;
      for (int i = 1; i <= n; i++)
        cout << i << " " << -(i * i + 343231) << endl;
    }
  }
}
