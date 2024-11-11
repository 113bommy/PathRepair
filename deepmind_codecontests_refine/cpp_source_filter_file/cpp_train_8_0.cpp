#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  char s[a];
  int cnt = 0;
  for (int i = 0; i < a; i++) {
    cin >> s[i];
    if (s[i] == '8') {
      cnt++;
    }
  }
  if (cnt >= 1 && a >= 11 == 0) {
    if (cnt < a / 11) {
      cout << cnt;
    } else {
      cout << a / 11;
    }
  } else {
    cout << 0;
  }
  return 0;
}
