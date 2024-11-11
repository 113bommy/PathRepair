#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum1 = 0, sum2 = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] == '4' || s[i] == '7') {
      sum1 += s[i] - '0';
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }
  for (int i = n / 2; i < n; i++) {
    if (s[i] != '4' || s[i] != '7') {
      sum2 += s[i] - '0';
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }
  if (sum1 != sum2)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
