#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> v;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  int m = 0;
  int k;
  for (int i = 0; i < 7; ++i) {
    k = 0;
    for (int j = 0; j < n; ++j) {
      if (v[j][i] == '1') ++k;
    }
    if (k > m) m = k;
  }
  cout << m;
}
