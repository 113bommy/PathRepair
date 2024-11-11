#include <bits/stdc++.h>
using namespace std;
long long int n;
string s;
int ints[(int)2e5 + 1];
char rgb[3] = {'R', 'G', 'B'};
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R')
      ints[i] = 0;
    else if (s[i] == 'G')
      ints[i] = 1;
    else
      ints[i] = 2;
  }
  long long int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (ints[i] == ints[i + 1]) {
      ans++;
      if (i + 2 <= n) {
        if (ints[i] == ints[i + 2])
          ints[i + 1] = (ints[i] + 1) % 3;
        else {
          if (ints[i] + ints[i + 2] == 1)
            ints[i + 1] = 2;
          else if (ints[i] + ints[i + 2] == 2)
            ints[i + 1] = 1;
          else if (ints[i] + ints[i + 2] == 3)
            ints[i + 1] = 0;
        }
      }
      ints[i + 1] = (ints[i] + 1) % 3;
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << rgb[ints[i]];
  }
}
