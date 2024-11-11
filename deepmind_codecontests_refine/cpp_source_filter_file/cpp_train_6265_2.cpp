#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  int negs = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(')
      cnt++;
    else {
      cnt--;
      negs = min(negs, cnt);
    }
  }
  negs = abs(negs);
  if (negs > 1 || cnt > 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
