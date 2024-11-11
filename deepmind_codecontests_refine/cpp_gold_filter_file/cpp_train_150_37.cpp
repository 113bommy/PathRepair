#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
string s;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    for (int j = 1; j < n; j++)
      if (s[i] == '*' && s[i + j] == '*' && s[i + 2 * j] == '*' &&
          s[i + 3 * j] == '*' && s[i + 4 * j] == '*') {
        cout << "yes";
        return 0;
      }
  cout << "no";
  return 0;
}
