#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string str;
  cin >> n >> str;
  bool isFirst = true;
  int ans = 0;
  int lastInd = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] != '.') {
      if (isFirst) {
        if (str[i] == 'R') {
          ans += i - 0;
        }
        isFirst = false;
      } else {
        if (str[i] == 'R') {
          ans += i - lastInd - 1;
        } else if (str[i] == 'L') {
          if ((i - lastInd - 1) % 2 != 0) ans++;
        }
      }
      lastInd = i;
    }
  }
  if (isFirst) {
    cout << n;
  } else {
    if (str[lastInd] == 'L') {
      ans += n - 1 - lastInd;
    }
    cout << ans;
  }
  int end;
  cin >> end;
  return 0;
}
