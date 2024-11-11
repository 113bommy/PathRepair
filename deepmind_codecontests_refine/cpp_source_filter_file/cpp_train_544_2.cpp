#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, count1, count2;
  cin >> t;
  while (t--) {
    string b;
    cin >> b;
    int c = b.length();
    count1 = 0;
    count2 = 0;
    for (i = 0; i < c; i++) {
      if (b[i] == '0') {
        count1++;
      } else {
        count2++;
      }
    }
    if (min(count1, count2) % 2 == 1) {
      cout << "ERA" << endl;
    } else {
      cout << "NET" << endl;
    }
  }
}
