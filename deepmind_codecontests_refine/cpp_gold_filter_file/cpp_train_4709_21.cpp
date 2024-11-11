#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[101], ans[101];
  cin >> a;
  int c = 0, i;
  for (i = 1; a[i] != '\0'; i++) {
    if (isupper(a[i]))
      ans[i] = tolower(a[i]);
    else
      c = 1;
  }
  if (c == 0) {
    if (isupper(a[0]))
      ans[0] = tolower(a[0]);
    else
      ans[0] = toupper(a[0]);
  } else {
    cout << a << endl;
    return 0;
  }
  ans[i] = '\0';
  cout << ans << endl;
  return 0;
}
