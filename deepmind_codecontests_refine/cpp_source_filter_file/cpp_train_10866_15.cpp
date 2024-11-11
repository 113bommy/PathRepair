#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using lld = long double;
using ulli = unsigned long long int;
using pll = pair<lli, lli>;
using ttt = pair<lli, pll>;
using vttt = vector<ttt>;
using vll = vector<pll>;
using vl = vector<lli>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using cd = complex<lld>;
void sanjeev(int kkkk) {
  int n, q;
  cin >> n >> q;
  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    v[i] = k;
  }
  vector<int> inc(n + 1, 0);
  vector<int> dec(n + 1, 0);
  for (int i = n - 1; i > 0; i--) {
    if (v[i] <= v[i + 1]) {
      inc[i] = inc[i + 1] + 1;
    }
  }
  for (int i = n - 1; i > 0; i--) {
    if (v[i] >= v[i + 1]) {
      dec[i] = dec[i + 1] + 1;
    }
  }
  vector<pair<int, int>> query;
  for (int i = 0; i < q; i++) {
    int s, e;
    cin >> s >> e;
    query.push_back(make_pair(s, e));
  }
  for (int i = 0; i < q; i++) {
    int s, e;
    s = query[i].first;
    e = query[i].second;
    if (inc[s] + s >= e) {
      cout << "YES";
    } else if (dec[s] + s >= e) {
      cout << "YES";
    } else if (dec[inc[s] + s] + inc[s] + s >= e)
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }
}
int main() {
  if (!0) ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);
  int t = 1;
  for (int i = 0; i < t; i++) {
    sanjeev(i + 1);
  }
  if (0) system("pause");
}
