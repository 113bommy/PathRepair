#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 10;
ll res;
ll a[N];
map<ll, ll> mp;
vector<int> s;
void solve() {
  string s;
  cin >> s;
  s = "###############" + s;
  int n = s.size();
  string a = s.substr(n - 2, n);
  string b = s.substr(n - 4, n);
  string c = s.substr(n - 5, n);
  int x = a.compare("po");
  int y = b.compare("desu");
  int z = b.compare("masu");
  int l = c.compare("mnida");
  if (x == 0) {
    cout << "FILIPINO" << endl;
    return;
  } else if (y == 0 || z == 0) {
    cout << "JAPANESE" << endl;
    return;
  } else if (l == 0) {
    cout << "KOREAN" << endl;
    return;
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
