#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int w = 0, b = 0, k = 0, i, j, d = 0;
  vector<int> v;
  char a;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'W')
      w++;
    else
      b++;
  }
  if (w % 2 != 0 && b % 2 != 0)
    cout << -1 << endl;
  else if (w == s.size() || b == s.size())
    cout << 0 << endl;
  else {
    for (i = 1; i + 1 < s.size(); i++) {
      if (s[i] != s[i - 1]) {
        if (s[i] == 'W' && s[i + 1] == 'W') {
          s[i] = s[i + 1] = 'B';
          k++;
        } else if (s[i] == 'B' && s[i + 1] == 'B') {
          s[i] = s[i + 1] = 'W';
          k++;
        } else {
          swap(s[i], s[i + 1]);
          k++;
        }
        v.push_back(i);
      }
    }
    if (s[i] != s[i - 1]) {
      k = k + i / 2;
      j = 0;
      while (j < i) {
        v.push_back(j);
        j = j + 2;
      }
    }
    cout << k << endl;
    for (i = 0; i < k; i++) cout << v[i] << " ";
  }
}
