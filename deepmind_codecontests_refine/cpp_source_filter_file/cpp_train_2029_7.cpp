#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  string g = s;
  long long int n = s.size();
  long long int c = 0, k = 0;
  for (long long int i = 0; i < n - 1; i++) {
    if (s[i] == 'A' && s[i + 1] == 'B') {
      c++;
      s[i] = 'X';
      s[i + 1] = 'X';
      break;
    }
  }
  for (long long int i = 0; i < n - 1; i++) {
    if (s[i] == 'B' && s[i + 1] == 'A') {
      c++;
      s[i] = 'X';
      s[i + 1] = 'X';
      break;
    }
  }
  for (long long int i = 0; i < n - 1; i++) {
    if (g[i] == 'A' && g[i + 1] == 'B') {
      k++;
      g[i] = 'X';
      g[i + 1] = 'X';
      break;
    }
  }
  for (long long int i = 0; i < n - 1; i++) {
    if (g[i] == 'B' && g[i + 1] == 'A') {
      k++;
      g[i] = 'X';
      g[i + 1] = 'X';
      break;
    }
  }
  (k == 2 || c == 2) ? cout << "YES" : cout << "NO";
}
