#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int u = 0, r = 0;
  int count = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      u++;
    }
    if (s[i] == 'R') {
      r++;
    }
    v.push_back(r - u);
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 0 &&
        ((v[i + 1] < 0 && v[i - 1] > 0) || (v[i + 1] > 0 && v[i - 1] < 0))) {
      count++;
    }
  }
  cout << count;
}
