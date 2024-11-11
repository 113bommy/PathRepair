#include <bits/stdc++.h>
using namespace std;
int n, m;
string s1, s2;
map<string, string> m1, m2;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> s1 >> s2;
    m1[s1] = s2;
    m2[s2] = s1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> s1;
    if (m1[s1] == "") {
      if (s1.length() <= m2[s1].length())
        cout << s1;
      else
        cout << m2[s1];
      cout << " ";
    } else {
      if (s1.length() < m1[s1].length())
        cout << s1;
      else
        cout << m1[s1];
      cout << " ";
    }
  }
}
