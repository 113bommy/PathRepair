#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
int n;
set<string> x;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  while (n--) {
    cin >> s;
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    x.insert(s);
  }
  cout << x.size() << endl;
  return 0;
}
