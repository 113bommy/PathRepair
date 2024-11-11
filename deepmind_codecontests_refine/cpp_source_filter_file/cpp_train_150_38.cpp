#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    for (int len = 1; i + 4 * len < n; len++) {
      bool flag = false;
      for (int j = 0; j < 5; j++)
        if (s[i + j * len] == '.') flag = false;
      if (!flag) {
        cout << "yes\n";
        return 0;
      }
    }
  cout << "no\n";
  return 0;
}
