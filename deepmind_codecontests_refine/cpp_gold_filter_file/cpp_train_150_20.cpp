#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  vector<int> v;
  int d = 0, cur = 0, dis, m = 1e5, countm = 0;
  cin >> n;
  getchar();
  cin >> s;
  if (s.size() < 2) {
    cout << "no" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      v.push_back(i);
    }
  }
  if (v.size() != 0) {
    for (int i = 0; i < v.size() - 1; i++) {
      dis = v[i + 1] - v[i];
      d = max(d, dis);
      m = min(m, dis);
    }
  }
  int count = 0;
  if (d != 0) {
    for (int i = v[0]; i < s.size() - d;) {
      if (s[i + d] == '*') {
        count++;
        i += d;
      } else
        i++;
      if (count > 4) {
        break;
      }
    }
  }
  if (count < 4 && m != 1e5) {
    for (int i = v[0]; i < s.size() - m;) {
      if (s[i + m] == '*') {
        countm++;
        i += m;
      } else if (s[i + m] != '*')
        break;
      if (count > 4) {
        break;
      }
    }
  }
  if (count >= 4 || countm >= 4) {
    cout << "yes" << endl;
  } else
    cout << "no" << endl;
  return 0;
}
