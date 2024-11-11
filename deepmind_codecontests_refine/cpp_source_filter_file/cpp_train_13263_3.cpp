#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 1, a = 0, i;
  string s, s1, s2;
  vector<int> v;
  cin >> s1;
  for (i = s1.size() - 1; i >= 0; i--) {
    if (s1[i] != ',') {
      a += (s1[i] - '0') * m;
      m *= 10;
    } else {
      v.push_back(a);
      m = 1;
      a = 0;
    }
  }
  v.push_back(a);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout << v[0];
  for (i = 0; i < v.size() - 1; i++) {
    if (v[i + 1] - v[i] > 1) {
      if (n > 1) {
        cout << "-" << v[i];
      }
      cout << "," << v[i + 1];
      n = 0;
    }
    if (v[i + 1] - v[i] == 1) {
      n++;
    }
  }
  if (n > 1) {
    cout << "-" << v[i];
  }
  return 0;
}
