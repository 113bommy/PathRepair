#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 100;
long long int b[N], ans[N];
int main() {
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  cout << "Mike" << '\n';
  bool ok = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    for (int j = s[i] - 97; j < 26; j++) {
      b[j] = 1;
    }
    ok = 0;
    for (int j = 0; j < s[i + 1] - 97; j++) {
      if (b[j] == 1) {
        if (j < s[i + 1] - 97) {
          cout << "Ann" << '\n';
          ok = 1;
          break;
        }
      }
    }
    if (!ok) cout << "Mike" << '\n';
  }
}
