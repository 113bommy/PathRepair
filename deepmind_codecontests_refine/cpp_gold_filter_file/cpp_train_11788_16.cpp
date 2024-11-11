#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  for (int i = 0; i < test; i++) {
    string s;
    cin >> s;
    int j = 0, c = 0;
    while (s[j] == (char)48) {
      j++;
      c++;
    }
    int d = 0;
    for (int i = c; i < s.length(); i++) {
      if (s[i] == (char)49) d = i;
    }
    int k = 0;
    if (s[0] == (char)49) {
      for (int i = 0; i <= d; i++) {
        if (s[i] == (char)48) k++;
      }
    } else {
      for (int i = c + 1; i <= d; i++) {
        if (s[i] == (char)48) k++;
      }
    }
    cout << k << endl;
  }
}
