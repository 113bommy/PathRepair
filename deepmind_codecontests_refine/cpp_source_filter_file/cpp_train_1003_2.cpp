#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> mp, mk;
set<long long int> s1, s2;
vector<long long int> v, w;
long long int a[2000006], b[2000006];
string s = "", p = "", q = "";
char ch;
long long int m, n, c, d, i, j, k, l, r, x, t, y, u, e, f, g, h;
int main() {
  cin >> n;
  cin >> x;
  for (i = 1; i <= n; i++) {
    cin >> y;
    if (abs(x - y) > 1) {
      cout << "NO" << endl;
      return 0;
    }
    x = y;
  }
  cout << "YES";
}
