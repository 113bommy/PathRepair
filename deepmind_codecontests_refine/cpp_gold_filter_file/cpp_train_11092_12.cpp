#include <bits/stdc++.h>
using namespace std;
int T, n, k, mn, p[200005];
map<int, long long int> mp1, mp2;
set<int> st;
string str, str1;
vector<int> ot;
int main() {
  while (cin >> n) {
    mn = 2000000000;
    cin >> str;
    for (int u = 0; u < n; ++u) cin >> p[u];
    for (int i = 0; i < str.size() - 1; ++i)
      if (str[i] == 'R' && str[i + 1] == 'L')
        mn = min(mn, abs(p[i + 1] - p[i]) / 2);
    if (mn == 2000000000)
      cout << "-1\n";
    else
      cout << mn << endl;
  }
}
