#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  map<string, string> m;
  for (int i = 0; i < t; i++) {
    string a, b;
    cin >> a >> b;
    m[a] = b;
  }
  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1;
    s2 = m[s1];
    if (s1.size() < s2.size())
      cout << s1 << " ";
    else
      cout << s2 << " ";
  }
}
