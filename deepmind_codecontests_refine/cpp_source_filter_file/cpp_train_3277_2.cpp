#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mx = 1e5;
string second;
int m;
bool reversed[mx + 1];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> second >> m;
  int n = (int)(second).size();
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    --a;
    reversed[a] = !reversed[a];
    reversed[n - a] = !reversed[n - a];
  }
  bool b = 0;
  for (int i = 0; i < n; ++i) {
    if (reversed[i]) b = !b;
    cout << (b ? second[n - 1 - i] : second[i]);
  }
  cout << '\n';
}
