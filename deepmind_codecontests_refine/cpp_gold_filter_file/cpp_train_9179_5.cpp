#include <bits/stdc++.h>
using namespace std;
string s;
int cnt, n, m;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i += 2) {
    if (s[i] == s[i + 1]) {
      cnt++;
      s[i] = 'b';
      s[i + 1] = 'a';
    }
  }
  printf("%d\n", cnt);
  cout << s;
}
