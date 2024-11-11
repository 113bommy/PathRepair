#include <bits/stdc++.h>
using namespace std;
const int base = 1e9 + 7;
void Solves() {
  string s, t;
  cin >> s >> t;
  long long n = min(s.length(), t.length()) - 1;
  long long id = 0;
  for (int i = 0; i <= n; i++) {
    if (s[s.length() - i - 1] != t[t.length() - i - 1])
      break;
    else
      id = i + 1;
  }
  cout << s.length() - id + t.length() - id;
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Solves();
}
