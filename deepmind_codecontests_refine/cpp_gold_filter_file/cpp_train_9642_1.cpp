#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O2")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int counts = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'S' && s[i + 1] == 'F') {
      counts++;
    } else if (s[i] == 'F' && s[i + 1] == 'S') {
      counts--;
    }
  }
  if (counts > 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
