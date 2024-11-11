#include <bits/stdc++.h>
using namespace std;
int main() {
  string n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v(10, 0), v1(10, 0);
  for (int i = 0; i < n.size(); ++i) {
    if (n[i] - '0' == 9)
      ++v[6];
    else if (n[i] - '0' == 5)
      ++v[2];
    else
      ++v[n[i] - '0'];
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] - '0' == 9)
      ++v1[6];
    else if (s[i] - '0' == 5)
      ++v1[2];
    else
      ++v1[s[i] - '0'];
  }
  int minz = s.size();
  for (int i = 0; i < 10; ++i) {
    if (i != 5 && i != 9) {
      if (v[i] == 0) continue;
      if (v1[i] / v[i] < minz) minz = v1[i] / v[i];
    }
  }
  cout << minz;
}
