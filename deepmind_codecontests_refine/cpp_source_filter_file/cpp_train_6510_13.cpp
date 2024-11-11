#include <bits/stdc++.h>
using namespace std;
const int SIZE = 10;
const long long int MOD = (int)1e9 + 7;
const int MAXM = 2000;
const int STR_SIZE = 100;
const int INF = (int)1e9 + 7;
const long double PI = acosl(-1);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> lang;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (lang.count(t - 1) == 0)
      lang.insert(make_pair(t - 1, 1));
    else
      lang[t - 1]++;
  }
  int m;
  cin >> m;
  vector<int> b, c;
  copy_n(istream_iterator<int>(cin), n, back_inserter(b));
  copy_n(istream_iterator<int>(cin), n, back_inserter(c));
  pair<int, int> max = make_pair(-1, -1);
  int max_id = 0;
  for (int i = 0; i < m; i++) {
    pair<int, int> res = make_pair(lang[b[i] - 1], lang[c[i] - 1]);
    if (res > max) {
      max = res;
      max_id = i + 1;
    }
  }
  cout << max_id << endl;
}
