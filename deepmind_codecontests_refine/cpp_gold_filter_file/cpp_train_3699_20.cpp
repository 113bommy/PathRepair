#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 100;
template <class T>
T sqr(T x) {
  return x * x;
}
int n;
string s;
char cc[3] = {'B', 'G', 'R'};
int main() {
  cin >> n;
  cin >> s;
  int ans = 0;
  map<char, int> c;
  for (int i = 0; i < n; i++) c[s[i]]++;
  if (c.size() == 1) {
    cout << c.begin()->first;
    return 0;
  }
  if (c.size() == 3) {
    cout << "BGR";
    return 0;
  }
  if (c.size() == 2) {
    int ok = 2;
    for (int i = 0; i < 3; i++) {
      if (c[cc[i]] < 2) ok -= 1;
    }
    if (ok == 1) {
      cout << "BGR";
    } else {
      if (ok == -1) {
        for (int i = 0; i < 3; i++) {
          if (c[cc[i]] == 0) cout << cc[i];
        }
        return 0;
      }
      for (int i = 0; i < 3; i++) {
        if (c[cc[i]] == 0 || c[cc[i]] == 1) cout << cc[i];
      }
    }
  }
  return 0;
}
