#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 0; i <= 3; i++) {
    string s;
    getline(cin, s);
    int cnt = 0;
    for (auto a : s) {
      if (a == 'e' || a == 'o' || a == 'a' || a == 'i' || a == 'u') cnt++;
    }
    if (i == 1 || i == 3) {
      if (cnt != 5) {
        cout << "NO";
        return 0;
      }
    } else {
      if (cnt != 7) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
  }
}
