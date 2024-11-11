#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int f = 0;
  string sl;
  cin >> sl;
  int a[26] = {0};
  transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
  for (int i = 0; i < n; i++) {
    a[sl[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (a[i] == 0) {
      f = 1;
      cout << "NO";
      break;
    }
  }
  if (f == 0) cout << "YES";
}
