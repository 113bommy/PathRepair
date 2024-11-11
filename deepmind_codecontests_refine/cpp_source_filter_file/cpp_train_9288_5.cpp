#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;
int t, n, d;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> d;
    if (d <= n)
      cout << "YES";
    else {
      int minn = oo;
      for (int i = 1; i * i <= n; i++)
        minn = min(minn, i + (d / (i + 1)) + min(d % (i + 1), 1));
      if (minn <= n)
        cout << "YES";
      else
        cout << "NO";
    }
    cout << "\n";
  }
}
