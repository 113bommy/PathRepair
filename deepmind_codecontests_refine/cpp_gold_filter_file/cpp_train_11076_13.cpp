#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  long long int i, length, cnt = 0, res = 0;
  length = a.size();
  for (i = 0; i < length; i++) {
    if (a[i] == 'h' && a[i + 1] == 'e' && a[i + 2] == 'a' && a[i + 3] == 'v' &&
        a[i + 4] == 'y')
      cnt++;
    else if (a[i] == 'm' && a[i + 1] == 'e' && a[i + 2] == 't' &&
             a[i + 3] == 'a' && a[i + 4] == 'l')
      res += cnt;
  }
  cout << res << endl;
  return 0;
}
