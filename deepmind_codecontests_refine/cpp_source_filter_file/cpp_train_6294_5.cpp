#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 9;
int main() {
  ios::sync_with_stdio(false);
  string t[4];
  bool f = 0;
  cin >> t[0] >> t[1] >> t[2];
  for (int i = 0; i < 3; i++) {
    if (t[i] == "A>B" || t[i] == "B<A") {
      for (int j = 0; j < 3; j++) {
        if (t[j] == "A>C" || t[j] == "C<A") {
          for (int k = 0; k < 3; k++) {
            if (t[k] == "B>C" || t[k] == "C<B") {
              f = 1;
              cout << "CBA" << endl;
            } else if (t[k] == "B<C" || t[k] == "C>B") {
              f = 1;
              cout << "BCA" << endl;
            }
          }
        } else if (t[j] == "A<C" || t[j] == "C>A") {
          for (int k = 0; k < 3; k++) {
            if (t[k] == "B<C" || t[k] == "C>B") {
              f = 1;
              cout << "BAC" << endl;
            }
          }
        }
      }
    } else if (t[i] == "A<B" || t[i] == "B>A") {
      for (int j = 0; j < 3; j++) {
        if (t[j] == "B>C" || t[j] == "C<B") {
          for (int k = 0; k < 3; k++) {
            if (t[k] == "A>C" || t[k] == "C<A") {
              f = 1;
              cout << "CAB" << endl;
            } else if (t[k] == "A<C" || t[k] == "C>A") {
              f = 1;
              cout << "ACB" << endl;
            }
          }
        } else if (t[j] == "C>B" || t[j] == "B<C") {
          for (int k = 0; k < 3; k++) {
            if (t[k] == "A<C" || t[k] == "C>A") {
              f = 1;
              cout << "ABC" << endl;
            }
          }
        }
      }
    }
    if (!f) cout << "Impossible" << endl;
  }
  return 0;
}
