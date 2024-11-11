#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0) {
      if (b == 0) {
        if (c == 0) {
          cout << "Tidak Tidak Tidak Ya"
               << "\n";
        } else {
          if (d == 0)
            cout << "Tidak Tidak Ya Tidak"
                 << "\n";
          else
            cout << "Tidak Tidak Ya Ya"
                 << "\n";
        }
      } else if (b % 2 == 0) {
        if (d == 0)
          cout << "Tidak Tidak Ya Tidak"
               << "\n";
        else
          cout << "Tidak Tidak Ya Ya"
               << "\n";
      } else {
        if (d == 0)
          cout << "Tidak Ya Tidak Tidak"
               << "\n";
        else
          cout << "Ya Ya Tidak Tidak"
               << "\n";
      }
    } else if (a % 2 == 0) {
      if (b == 0) {
        if (c == 0)
          cout << "Tidak Tidak Tidak Ya"
               << "\n";
        else
          cout << "Tidak Tidak Ya Ya"
               << "\n";
      } else if (b % 2 == 0) {
        cout << "Tidak Tidak Ya Ya"
             << "\n";
      } else {
        cout << "Ya Ya Tidak Tidak"
             << "\n";
      }
    } else {
      if (b == 0) {
        if (c == 0)
          cout << "Ya Tidak Tidak Tidak"
               << "\n";
        else
          cout << "Ya Ya Tidak Tidak"
               << "\n";
      } else if (b % 2 == 0) {
        cout << "Ya Ya Tidak Tidak"
             << "\n";
      } else {
        cout << "Tidak Tidak Ya Ya"
             << "\n";
      }
    }
  }
  return 0;
}
