#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  bool ok1 = false, ok2 = false;
  cin >> s;
  int n = s.length();
  if (n <= 3) {
    cout << "NO";
    return 0;
  }
  vector<int> v1;
  vector<int> v2;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == 'A' && s[i + 1] == 'B')
      v1.push_back(i);
    else if (s[i] == 'B' && s[i + 1] == 'A')
      v2.push_back(i);
  }
  if (v1.empty() || v2.empty())
    cout << "NO";
  else {
    for (int i = 0; i < (int)v1.size(); ++i) {
      for (int j = 0; j < (int)v2.size(); ++j) {
        if (abs(v1[i] - v2[i]) > 1) {
          cout << "YES";
          return 0;
        }
      }
    }
    cout << "NO";
  }
}
