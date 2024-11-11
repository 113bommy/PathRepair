#include <bits/stdc++.h>
using namespace std;
int main() {
  int length, operations;
  cin >> length >> operations;
  string enter;
  getline(cin, enter);
  string strOfLength;
  getline(cin, strOfLength);
  for (int i = 1; i <= operations; i++) {
    int l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;
    for (int j = l; j <= r; j++) {
      if (strOfLength[j] == c1) {
        strOfLength[j] = c2;
      }
    }
  }
  cout << strOfLength;
  return 0;
}
