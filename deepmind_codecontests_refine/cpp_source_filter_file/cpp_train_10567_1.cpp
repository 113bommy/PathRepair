#include <bits/stdc++.h>
using namespace std;
const string LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const long long LINF = (long long)9e18 + 7;
string s;
int n;
int main() {
  cin >> s >> n;
  for (long long asdfasdf = 0; asdfasdf < (long long)n; asdfasdf++) {
    int l, r, d;
    cin >> l >> r >> d;
    l--;
    r--;
    int q = 0;
    if (l < r) q = d % (r - l);
    string s1 = "";
    for (int i = 0; i < l; i++) s1 += s[i];
    for (int i = r - q + 1; i <= r; i++) s1 += s[i];
    for (int i = l; i <= r - q; i++) s1 += s[i];
    for (int i = r + 1; i < s.size(); i++) s1 += s[i];
    s = s1;
  }
  cout << s;
}
