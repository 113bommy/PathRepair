#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, d, j, a[1000] = {}, l = 0, cnt = 0, max = 0;
  cin >> n >> d;
  string s;
  for (i = 0; i < d; i++) {
    cin >> s;
    for (j = 0; j < n; j++) {
      if (s[j] == '0') {
        a[l] = i + 1;
        l++;
        break;
      }
    }
  }
  for (i = 0; i < l; i++) {
    if (a[i] == a[i + 1] - 1) {
      cnt++;
      if (max < cnt) max = cnt;
    } else
      cnt = 0;
  }
  if (l == 0)
    cout << max;
  else
    cout << max + 1;
}
