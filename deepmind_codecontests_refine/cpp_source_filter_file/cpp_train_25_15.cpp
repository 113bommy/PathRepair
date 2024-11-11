#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s[n];
    long long int cntU = 0, cntD = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> s[i];
    }
    if (s[0][1] == '0' && s[1][0] == '0') {
      if (s[n - 2][n - 1] == '1' && s[n - 1][n - 2] == '1') {
        cout << "0" << endl;
      } else if (s[n - 2][n - 1] == '0' && s[n - 1][n - 2] == '0') {
        cout << "2" << endl
             << n - 1 << " " << n << endl
             << n << " " << n - 1 << endl;
      } else if (s[n - 2][n - 1] == '0' && s[n - 1][n - 2] == '1') {
        cout << "1" << endl << n - 1 << " " << n << endl;
      } else if (s[n - 2][n - 1] == '1' && s[n - 1][n - 2] == '0') {
        cout << "1" << endl << n << " " << n - 1 << endl;
      }
    } else if (s[0][1] == '1' && s[1][0] == '1') {
      if (s[n - 2][n - 1] == '0' && s[n - 1][n - 2] == '0') {
        cout << "0" << endl;
      } else if (s[n - 2][n - 1] == '1' && s[n - 1][n - 2] == '1') {
        cout << "2" << endl
             << n - 1 << " " << n << endl
             << n << " " << n - 1 << endl;
      } else if (s[n - 2][n - 1] == '1' && s[n - 1][n - 2] == '0') {
        cout << "2" << endl << n - 1 << " " << n << endl;
      } else if (s[n - 2][n - 1] == '0' && s[n - 1][n - 2] == '1') {
        cout << "2" << endl << n << " " << n - 1 << endl;
      }
    } else if (s[0][1] == '0' && s[1][0] == '1') {
      if (s[n - 2][n - 1] == '0' && s[n - 1][n - 2] == '0') {
        cout << "1" << endl
             << "1"
             << " "
             << "2" << endl;
      } else if (s[n - 2][n - 1] == '1' && s[n - 1][n - 2] == '1') {
        cout << "1" << endl
             << "2"
             << " "
             << "1" << endl;
      } else if (s[n - 2][n - 1] == '1' && s[n - 1][n - 2] == '0') {
        cout << "2" << endl
             << n - 1 << " " << n << endl
             << "1"
             << " "
             << "2" << endl;
      } else if (s[n - 2][n - 1] == '0' && s[n - 1][n - 2] == '1') {
        cout << "2" << endl
             << n << " " << n - 1 << endl
             << "1"
             << " "
             << "2" << endl;
      }
    } else if (s[0][1] == '1' && s[1][0] == '0') {
      if (s[n - 2][n - 1] == '0' && s[n - 1][n - 2] == '0') {
        cout << "1" << endl
             << "2"
             << " "
             << "1" << endl;
      } else if (s[n - 2][n - 1] == '1' && s[n - 1][n - 2] == '1') {
        cout << "1" << endl
             << "1"
             << " "
             << "2" << endl;
      } else if (s[n - 2][n - 1] == '1' && s[n - 1][n - 2] == '0') {
        cout << "2" << endl
             << n << " " << n - 1 << endl
             << "1"
             << " "
             << "2" << endl;
      } else if (s[n - 2][n - 1] == '0' && s[n - 1][n - 2] == '1') {
        cout << "2" << endl
             << n << " " << n - 1 << endl
             << "2"
             << " "
             << "1" << endl;
      }
    }
  }
  return 0;
}
