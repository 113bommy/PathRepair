#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
template <typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
  return os << '{' << p.first << ", " << p.second << '}';
}
const int oo = 0x3f3f3f3f;
const ll OO = ll(oo) * oo;
const int N = 100005;
vi pos[26];
bool mark[26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string a;
  cin >> a;
  string b;
  cin >> b;
  int n = int((a).size());
  for (int i = 0; i < n; i++) {
    mark[a[i] - 'a'] = true;
    pos[a[i] - 'a'].emplace_back(i);
  }
  for (int i = 0; i < 26; i++) {
    if (!mark[i]) continue;
    pos[i].emplace_back(pos[i][0] + n);
  }
  int p = 1;
  int i = -1;
  for (const auto chr : b) {
    int c = chr - 'a';
    if (pos[c].empty()) {
      cout << -1 << endl;
      return 0;
    }
    int j = *lower_bound((pos[c]).begin(), (pos[c]).end(), i + 1);
    if (j >= n) {
      p++;
      i = j - n;
    } else if (j <= i) {
      p++;
      i = j;
    } else {
      i = j;
    }
  }
  cout << p << endl;
  return 0;
}
