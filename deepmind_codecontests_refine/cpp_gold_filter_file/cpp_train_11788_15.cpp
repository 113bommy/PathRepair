#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char s[100];
    cin >> s;
    int l = strlen(s);
    int i, mx = 0, c = 0, sum = 0, j = 0, a[100];
    for (i = 0; i < l; i++) {
      if (s[i] == '1') {
        a[j] = i;
        j++;
      }
    }
    for (i = 0; i < j - 1; i++) {
      if (a[i + 1] - a[i] > 1) {
        c += ((a[i + 1] - a[i]) - 1);
      }
    }
    cout << c << endl;
  }
  return 0;
}
