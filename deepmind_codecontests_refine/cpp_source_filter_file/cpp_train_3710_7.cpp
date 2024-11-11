#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h1, a1, h2, a2, c;
  cin >> h1 >> a1 >> c;
  cin >> h2 >> a2;
  int k = 0, cnt = 0;
  while (h2 > 0) {
    if (k & 1) {
      h1 -= a2;
    } else {
      cnt++;
      if (h1 <= a2) {
        if (h2 <= a1) {
          h2 -= a1;
          str += "0";
        } else {
          h1 += c;
          str += "0";
        }
      } else {
        str += "1";
        h2 -= a1;
      }
    }
    k++;
  }
  cout << str.size() << "\n";
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '1') {
      cout << "STRIKE\n";
    } else
      cout << "HEAL\n";
  }
  return 0;
}
