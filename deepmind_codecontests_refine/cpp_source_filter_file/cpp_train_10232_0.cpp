#include <bits/stdc++.h>
using namespace std;
long long int t, n, c, m, d, x, y, l, r, i, j, a, b, e;
string s, p, q;
char ch, ck;
vector<long long int> v, w;
set<long long int> s1;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    c = 0, d = 1;
    for (i = 1; i < n; i++) {
      if (s[i] != s[i - 1])
        d++;
      else
        e++;
      e = min(e, d);
    }
    e += (d - e + 1) / 2;
    cout << e << endl;
  }
}
