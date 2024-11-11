#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char s[n];
  bool k = true;
  string s1;
  vector<string> v[n];
  int j = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if ((i != 0 && s[i] == s[i - 1]) && s[i] != '?') k = false;
  }
  if (k == false) {
    cout << "No" << endl;
    return 0;
  }
  long long res = 1, dem = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 && s[i] == '?' && s[i + 1] != '?') {
      res *= 2;
      continue;
    }
    if (i == n - 1 && s[i] == '?' && s[i - 1] != '?') {
      res *= 2;
      continue;
    }
    if (i == n - 1 && s[i] == '?' && s[i - 1] == '?') {
      res *= pow(2, dem);
      break;
    }
    if (s[i] == '?') {
      dem++;
    } else {
      if (dem == 1) {
        if (s[i - 2] == s[i]) res *= 2;
      } else if (dem != 0)
        res *= pow(2, (dem - 1));
      dem = 0;
    }
  }
  if (res != 1) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}
