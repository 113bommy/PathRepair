#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
char mtx[100][100];
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (ll i = 0; i < (ll)n; ++i) {
    for (ll j = 0; j < (ll)m; ++j) {
      cin >> mtx[i][j];
    }
  }
  for (ll i = 0; i < (ll)n; ++i) {
    vector<int> curRows;
    vector<int> curColumns;
    for (ll j = 0; j < (ll)m; ++j) {
      if (mtx[i][j] == '#') {
        curColumns.push_back(j);
        for (ll k = 0; k < (ll)m; ++k) {
          if (mtx[k][j] == '#') curRows.push_back(k);
        }
      }
    }
    for (ll j = 0; j < (ll)curRows.size(); ++j) {
      for (ll k = 0; k < (ll)curColumns.size(); ++k) {
        if (mtx[curRows[j]][curColumns[k]] != '#') {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
