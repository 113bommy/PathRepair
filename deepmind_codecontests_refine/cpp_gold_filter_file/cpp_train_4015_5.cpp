#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t, num, a[105];
  char s[105];
  for (i = 0; i < 105; i++) a[i] = 0;
  num = 0;
  cin >> t;
  for (i = 1; i <= t; i++) cin >> s[i];
  for (i = 1; i <= t; i++) {
    if (s[i] == 'B') num++;
    while (s[i] == 'B') {
      a[num]++;
      i++;
    }
  }
  cout << num << endl;
  for (i = 1; i <= num; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
