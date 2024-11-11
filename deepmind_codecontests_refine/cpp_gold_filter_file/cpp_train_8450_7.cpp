#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> v1, v2;
  int s1 = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    if (i < n / 2) {
      if (s[i] == '?')
        v1.push_back(i);
      else
        s1 += s[i] - '0';
    } else {
      if (s[i] == '?')
        v2.push_back(i);
      else
        s2 += s[i] - '0';
    }
  }
  if (v1.empty() && v2.empty()) {
    if (s1 != s2)
      cout << "Monocarp\n";
    else
      cout << "Bicarp\n";
  } else {
    if (s1 == s2) {
      if (v1.size() == v2.size())
        cout << "Bicarp\n";
      else
        cout << "Monocarp\n";
    } else {
      if (s1 < s2) swap(s1, s2), swap(v1, v2);
      s1 += (v1.size() - v1.size() / 2) * 9;
      if (v1.size() % 2 == 0)
        s2 += (v2.size() / 2) * 9;
      else
        s2 += (v2.size() - v2.size() / 2) * 9;
      if (s2 == s1)
        cout << "Bicarp\n";
      else
        cout << "Monocarp\n";
    }
  }
}
