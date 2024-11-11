#include <bits/stdc++.h>
using namespace std;
int vis[51];
int main() {
  string s;
  int n, len;
  cin >> n >> len;
  cin >> s;
  while (n--) {
    for (int i = 0; i < len; i++) {
      if (s[i] == 'B' && s[i + 1] == 'G') {
        swap(s[i], s[i + 1]);
        i++;
      }
    }
  }
  cout << s << endl;
  return 0;
}
