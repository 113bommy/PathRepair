#include <bits/stdc++.h>
using namespace std;
vector<int> sal;
vector<int> pos;
int main() {
  long long a, b, x, temp;
  cin >> a >> b;
  x = 0;
  temp = 10000000;
  string s, t, tsub;
  cin >> s >> t;
  for (int i = 0; i <= b - a; i++) {
    x = 0;
    tsub = t.substr(i, a);
    for (int j = 0; j < a; j++) {
      if (tsub[j] != s[j]) {
        x++;
        sal.push_back(j + 1);
      }
    }
    if (x < temp) {
      temp = x;
      pos.clear();
      for (int k = 0; k < sal.size(); k++) {
        pos.push_back(sal[k]);
      }
    }
    tsub.clear();
    sal.clear();
  }
  cout << temp << '\n';
  for (int k = 0; k < pos.size(); k++) {
    cout << pos[k] << " ";
  }
}
