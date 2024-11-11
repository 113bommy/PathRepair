#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int j = 0, k = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (j == 0) {
        cout << "1 1" << endl;
        j++;
      } else {
        cout << "3 1" << endl;
        j--;
      }
    } else {
      if (k == 0) {
        cout << "4 3" << endl;
        k++;
      } else {
        cout << "4 2" << endl;
        k--;
      }
    }
  }
  return 0;
}
