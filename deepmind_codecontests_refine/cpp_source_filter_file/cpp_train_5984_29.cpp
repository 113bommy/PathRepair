#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 10;
const long long INF = 1e18;
const long long inf = -1e18;
const long long MOD = 1e9 + 7;
const long long xesh = 31;
long long us[N], ans = 1;
string a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long o = 1;
  while (o--) {
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
      us[a[i]]++;
    }
    for (int i = 0; i < a.size(); i++) {
      ans += us[a[i]];
    }
    cout << ans;
  }
}
