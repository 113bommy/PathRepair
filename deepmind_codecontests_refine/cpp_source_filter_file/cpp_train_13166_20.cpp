#include <bits/stdc++.h>
using namespace std;
string s;
long long w[27], a, i, p;
map<int, int> m[123];
int main() {
  for (i = 0; i < 26; i++) cin >> w[i];
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    a += m[s[i]][p];
    p += w[s[i] - 'a'];
    m[s[i]][p]++;
  }
  cout << a;
}
