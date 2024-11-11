#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, a[5];
  cin >> s;
  bool f = false;
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
    if (s[0] == a[i][0] || s[0] == a[i][1] || s[1] == a[i][0] ||
        s[i] == a[i][1])
      f = true;
  }
  if (f)
    printf("YES");
  else
    printf("NO");
}
