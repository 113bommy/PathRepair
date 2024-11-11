#include <bits/stdc++.h>
using namespace std;
int t;
int n, k;
string a[1005];
int main() {
  cin >> t;
  while (t--) {
    int s[30] = {0};
    int sum = 0, flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i].size();
      for (int j = 0; j < a[i].size(); j++) {
        int t = a[i][j] - 'a';
        s[t]++;
      }
    }
    if (sum % n != 0) {
      cout << "NO" << endl;
      return 0;
    }
    for (int i = 0; i <= 26; i++) {
      if (s[i] % n != 0) flag = 1;
    }
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
