#include <bits/stdc++.h>
using namespace std;
bool helper(string &s, int n, int p) {
  char maxi = (p - 1 + 'a');
  for (int i = n - 1; i >= 0; i--) {
    for (char c = s[i] + 1; c <= maxi; c++) {
      if (i >= 1 && s[i - 1] == c) continue;
      if (i >= 2 && s[i - 2] == c) continue;
      s[i] = c;
      for (int j = i + 1; j < n; j++) {
        for (char ch = 'a'; ch <= maxi; ch++) {
          if (j >= 1 && s[j - 1] == ch) continue;
          if (j >= 2 && s[j - 1] == ch) continue;
          s[j] = ch;
          break;
        }
      }
      cout << s;
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  if (!helper(s, n, p)) cout << "NO";
  return 0;
}
