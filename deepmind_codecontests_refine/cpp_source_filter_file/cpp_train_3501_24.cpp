#include <bits/stdc++.h>
using namespace std;
char c1, c2;
int n, m, a, b;
string s;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c1 >> c2;
    for (int i = a - 1; i <= b; i++) {
      if (s[i] == c1) s[i] = c2;
    }
  }
  cout << s;
}
