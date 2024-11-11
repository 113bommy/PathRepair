#include <bits/stdc++.h>
using namespace std;
int main() {
  string t, s, tmp;
  cin >> t >> s;
  for (int i = 0; i < t.size(); i++) tmp.push_back('#');
  t = tmp + t + tmp;
  int mn = (1 << 30);
  for (int i = 0; i < t.size(); i++) {
    if (i + s.size() - 1 >= t.size()) break;
    int sum = 0;
    for (int j = 0; j < s.size(); j++) sum += (s[j] != t[i + j]);
    mn = min(mn, sum);
  }
  cout << mn << endl;
  return 0;
}
