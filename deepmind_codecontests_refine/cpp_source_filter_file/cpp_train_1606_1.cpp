#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, m, n, c = 0, d = 0;
  vector<int> v1, v2;
  cin >> n;
  string s1, s2;
  for (i = 0; i < n; i++) {
    cin >> j >> l;
    v1.push_back(j);
    v2.push_back(l);
    s1.push_back('0');
    s2.push_back('0');
  }
  for (i = 0; i < n; i++) {
    if (v1[c] <= v2[d]) {
      s1[c] = '1';
      c++;
    } else {
      s2[d] == '1';
      d++;
    }
  }
  for (i = 0; i < n / 2; i++) {
    s1[i] = '1';
    s2[i] = '1';
  }
  cout << s1 << endl;
  cout << s2 << endl;
  return 0;
}
