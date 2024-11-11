#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int id = 1000000007;
    for (int i = 0; i <= (int)s.size() - 1; ++i)
      if (s[i] == '8') {
        id = i;
        break;
      }
    if (n - id - 1 >= 11)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
