#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long int n, count, flag;
  n = s.length();
  count = flag = 0;
  if (n == 1)
    cout << n - 1 << endl;
  else {
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == s[n - i - 1])
        count++;
      else {
        count = 0;
        break;
      }
    }
    if (count == 0) {
      cout << n;
    } else {
      for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1])
          flag++;
        else {
          flag = 0;
          break;
        }
      }
      if (flag == 0)
        cout << n - 1 << endl;
      else
        cout << "0" << endl;
    }
  }
  return 0;
}
