#include <bits/stdc++.h>
using namespace std;
const int N = 200010, INF = INT_MIN;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, s1;
  cin >> s;
  long long int n = s.length(), d = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '/' && s[i] == s[i + 1])
      continue;
    else
      s1.push_back(s[i]);
  }
  for (long long int i = s1.length() - 1; i >= 0; i--) {
    if (s[i] != '/') {
      d = i;
      break;
    }
  }
  for (long long int i = 0; i < d; i++) cout << s1[i];
}
