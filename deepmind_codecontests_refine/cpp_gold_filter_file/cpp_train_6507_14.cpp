#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> v;
  string s;
  int mx = 0;
  while (getline(cin, s)) {
    int n = s.size();
    mx = max(mx, n);
    v.push_back(s);
  }
  mx += 2;
  for (int i = 0; i <= mx; ++i) {
    cout << "*\n"[i == (mx)];
  }
  int prev = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    cout << "*";
    int sz = v[i].size();
    int lshift = (mx - sz - 2) / 2;
    int rshift = lshift;
    if (((lshift + rshift + sz + 2) < mx)) {
      if (prev == 0) {
        ++rshift;
        prev = 1;
      } else if (prev == 1) {
        ++lshift;
        prev = 0;
      }
    }
    for (int i = 0; i < lshift; ++i) {
      cout << " ";
    }
    cout << v[i];
    for (int i = 0; i < rshift; ++i) {
      cout << " ";
    }
    cout << "*\n";
  }
  for (int i = 0; i < mx; ++i) {
    cout << "*\n"[i == (mx)];
  }
  return 0;
}
