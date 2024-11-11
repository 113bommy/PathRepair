#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2 && s[0] == s[1]) {
      printf("NO\n");
      continue;
    }
    printf("YES\n2\n");
    cout << s[0] << ' ';
    for (int i = 1; i < n; i++) cout << s[i];
    cout << endl;
  }
}
