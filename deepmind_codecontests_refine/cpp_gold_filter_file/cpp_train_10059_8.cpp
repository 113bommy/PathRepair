#include <bits/stdc++.h>
using namespace std;
const int mn = 10000 + 10;
int a[mn], b[mn];
string s;
int sz, val;
int main() {
  cin >> s;
  sz = s.size();
  if (s[0] == 'a')
    a[1] = 1;
  else
    b[1] = 1;
  for (int i = 2; i <= sz; i++) {
    if (s[i - 1] == 'a') {
      a[i] = a[i - 1] + 1;
      b[i] = b[i - 1];
    } else {
      b[i] = b[i - 1] + 1;
      a[i] = a[i - 1];
    }
  }
  int maxx = 0;
  for (int i = 0; i < sz; i++) {
    for (int j = i - 1; j < sz; j++) {
      val = a[i] + b[j + 1] - b[i] + a[sz] - a[j + 1];
      maxx = max(maxx, val);
    }
  }
  cout << maxx;
}
