#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j = 1;
  string s1[28], s;
  cin >> n;
  cin >> s;
  int mark[26];
  memset(mark, 0, sizeof(26));
  string::iterator it = s.begin(), it1 = s.begin();
  mark[*it - 'a'] = 1;
  it++;
  if (n == 1) {
    cout << "YES" << endl;
    cout << s;
    return 0;
  }
  while (it < s.end()) {
    if (j == n) {
      s1[j].assign(it1, s.end());
      cout << "YES" << endl;
      for (i = 1; i <= n; i++) {
        cout << s1[i] << endl;
      }
      return 0;
    }
    if (mark[*it - 'a'] == 1) {
      it++;
    } else {
      s1[j].assign(it1, it);
      it1 = it;
      j++;
      mark[*it - 'a'] = 1;
      it++;
    }
  }
  cout << "NO";
  return 0;
}
