#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000 + 7;
int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<int> v(9, 0);
  for (int i = 0; i < 9; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    if (v[str[i] - '0' - 1] > (str[i] - '0')) {
      for (int j = i; j < n; j++) {
        if (v[str[j] - '0' - 1] >= (str[j] - '0')) {
          cout << v[str[j] - '0' - 1];
        } else {
          for (int k = j; k < n; k++) {
            cout << str[k];
          }
          return 0;
        }
      }
      return 0;
    } else {
      cout << str[i];
    }
  }
  return 0;
}
