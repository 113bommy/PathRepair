#include <bits/stdc++.h>
using namespace std;
char a[15];
int k, ans, r = 1, i, j, cnt, res;
string s;
int main() {
  cin >> s >> k;
  for (i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '0') {
      res++;
    }
  }
  if (res < k) {
    cout << s.size() - 1;
    return 0;
  }
  for (i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '0')
      ans++;
    else
      cnt++;
    if (ans == k) {
      cout << cnt;
      return 0;
    }
  }
}
