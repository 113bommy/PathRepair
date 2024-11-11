#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int g = a + b;
    if (g % 2 == 1) {
      if (a > 0 || d > 0)
        cout << "Ya"
             << " ";
      else
        cout << "Tidak"
             << " ";
      if (b > 0 || c > 0)
        cout << "Ya"
             << " ";
      else
        cout << "Tidak"
             << " ";
      cout << "Tidak"
           << " ";
      cout << "Tidak"
           << " ";
    } else {
      cout << "Tidak"
           << " ";
      cout << "Tidak"
           << " ";
      if (a > 0 || d > 0)
        cout << "Ya"
             << " ";
      else
        cout << "Tidak"
             << " ";
      if (b > 0 || c > 0)
        cout << "Ya"
             << " ";
      else
        cout << "Tidak"
             << " ";
    }
    cout << endl;
  }
}
