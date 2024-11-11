#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, a;
  cin >> s >> a;
  int r = s.length();
  int q = a.length();
  int flag = 0;
  for (int i = 0; i < r; i++) {
    if (s[i] == a[q - i - 1]) {
      flag = 1;
    }
  }
  if (flag == 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
