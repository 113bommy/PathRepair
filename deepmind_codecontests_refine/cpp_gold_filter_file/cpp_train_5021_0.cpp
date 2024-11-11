#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int k = 0, l = 0, c = 0, d = 0, i, j = 0, cnt = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == '(')
      k++;
    else
      l++;
  }
  if (k != l)
    cout << "-1"
         << "\n";
  else {
    for (i = 0; i < n; i++) {
      if (s[i] == '(')
        c++;
      else if (c > 0)
        c--;
      else
        d++;
      if (c == 0 && d == 0) j = i + 1;
      if (c == d && c != 0) {
        c = d = 0;
        cnt += i - j + 1;
        j = i + 1;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
