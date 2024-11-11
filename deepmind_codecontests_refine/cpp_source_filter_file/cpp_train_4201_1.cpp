#include <bits/stdc++.h>
using namespace std;
int a[100000] = {0};
string s;
int main() {
  int min1 = 100000;
  cin >> s;
  int n = s.size();
  for (int i = 1; i <= n; i++)
    a[i] = a[i - 1] + (s[i - 1] >= 'A' && s[i - 1] <= 'Z' ? 1 : 0);
  if (a[n] == n || a[n] == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int m = (i - a[i]) + (a[n] - a[i]);
    min1 = min(min1, m);
  }
  cout << min1 << endl;
  return 0;
}
