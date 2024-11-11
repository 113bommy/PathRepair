#include <bits/stdc++.h>
using namespace std;
long long inf = 1000000007;
long long mod = 1000000007;
int main() {
  vector<vector<char>> v(10);
  for (int i = 1; i <= 9; ++i) {
    string tmp;
    string s;
    cin >> s;
    tmp = s;
    cin >> s;
    tmp += s;
    cin >> s;
    tmp += s;
    v[i].push_back('-');
    for (int j = 0; j < tmp.size(); ++j) {
      v[i].push_back(tmp[j]);
    }
  }
  int a, b;
  cin >> a >> b;
  int s, t;
  if (a % 3 == 1) {
    s = 1;
  } else if (b % 3 == 2) {
    s = 4;
  } else {
    s = 7;
  }
  if (b % 3 == 1) {
    t = 1;
  } else if (b % 3 == 2) {
    t = 4;
  } else {
    t = 7;
  }
  bool fl = false;
  for (int(i) = s; (i) < s + 3; ++(i)) {
    for (int(j) = t; (j) < t + 3; ++(j)) {
      if (v[i][j] == '.') {
        fl = true;
        v[i][j] = '!';
      }
    }
  }
  if (!fl) {
    for (int(i) = 1; (i) < 10; ++(i)) {
      for (int(j) = 1; (j) < 10; ++(j)) {
        if (v[i][j] == '.') {
          v[i][j] = '!';
        }
        cout << v[i][j];
        if (j % 3 == 0) {
          cout << " ";
        }
      }
      cout << endl;
      if (i % 3 == 0) {
        cout << endl;
      }
    }
  } else {
    for (int(i) = 1; (i) < 10; ++(i)) {
      for (int(j) = 1; (j) < 10; ++(j)) {
        cout << v[i][j];
        if (j % 3 == 0) {
          cout << " ";
        }
      }
      cout << endl;
      if (i % 3 == 0) {
        cout << endl;
      }
    }
  }
  return 0;
}
