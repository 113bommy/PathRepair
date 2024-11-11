#include <bits/stdc++.h>
using namespace std;
char s[100010];
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cin >> s + 1;
  int t = min(a, b);
  int k = max(a, b);
  if (s[a] == s[b])
    cout << '0' << endl;
  else {
    for (int i = t; i <= n; i++) {
      if (s[i] == s[k]) {
        cout << i - t << endl;
        break;
      }
      t++;
    }
  }
}
