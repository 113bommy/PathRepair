#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, j, k, m, n, x, y;
  t = 1;
  while (t--) {
    long long int flag = 0;
    cin >> n;
    string s;
    cin >> s;
    vector<long long int> ar(10, 0);
    for (i = 1; i <= 9; i++) {
      cin >> ar[i];
    }
    for (i = 0; i < n; i++) {
      x = s[i] - '0';
      if (x < ar[x]) {
        while (i < n && x < ar[x]) {
          s[i] = char(ar[x] + '0');
          i++;
          x = s[i] - '0';
        }
        break;
      }
    }
    cout << s;
  }
  return 0;
}
