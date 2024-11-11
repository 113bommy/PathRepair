#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<char> v;
  vector<char> v2;
  for (int i = n - 2; i >= 0; i -= 2) {
    v.push_back(s[i]);
  }
  for (int i = n - 1; i >= 0; i -= 2) {
    v2.push_back(s[i]);
  }
  for (int i = 0; i < v.size(); i++) cout << v[i];
  for (int i = v2.size() - 1; i >= 0; i--) cout << v2[i];
  return 0;
}
