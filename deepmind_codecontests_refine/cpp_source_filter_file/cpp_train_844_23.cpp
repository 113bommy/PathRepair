#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  if (n == 1) {
    cout << "a";
  } else if (n == 2) {
    cout << "b";
  } else if (n == 3) {
    cout << "abc";
  } else {
    string s = "abcd";
    cout << "abcd";
    for (i = 4; i <= n; i = i + 4) {
      if (i + 4 <= n) {
        cout << s;
      } else if (i + 3 <= n) {
        cout << "abc";
      } else if (i + 2 <= n) {
        cout << "ab";
      } else if (i + 1 <= n) {
        cout << "a";
      }
    }
  }
}
