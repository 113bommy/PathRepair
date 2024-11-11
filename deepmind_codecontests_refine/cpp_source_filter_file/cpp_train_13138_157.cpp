#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  };
  string s;
  cin >> s;
  int n = s.size();
  vector<int> p(n);
  p[0] = 0;
  for (int i = 1; i < n; i++) {
    int a = p[i - 1];
    while (a > 0 && s[i] != s[a]) {
      a = p[a - 1];
    }
    if (s[a] == s[i]) a++;
    p[i] = a;
  }
  if (p[n - 1] == 0)
    cout << "Just a legend" << endl;
  else {
    int boo = 0;
    for (int i = 0; i < n - 1; i++) {
      if (p[i] == p[n - 1]) boo = 1;
    }
    if (boo)
      cout << s.substr(0, p[n - 1]) << endl;
    else {
      if (p[p[n - 1]] == 0)
        cout << "Just a legend" << endl;
      else {
        cout << s.substr(0, p[p[n - 1]]) << endl;
      }
    }
  }
  return 0;
}
