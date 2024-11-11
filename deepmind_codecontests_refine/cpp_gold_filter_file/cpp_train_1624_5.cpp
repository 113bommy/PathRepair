#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
string a;
int n;
string b[100005];
pair<int, int> c[N];
set<string> s[12];
vector<int> g[100005];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> a;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) s[b[i].size()].insert(b[i]);
  for (int i = 0; i < (int)a.size(); i++) {
    string aux;
    aux.clear();
    for (int j = i; j < min(i + 10, (int)a.size()); j++) {
      aux += a[j];
      if (s[aux.size()].count(aux) == 1) g[i].push_back(j);
    }
  }
  int k, r;
  k = -1;
  int p = a.size();
  for (int i = a.size() - 1; i >= 0; i--) {
    for (int u : g[i]) p = min(p, u);
    if (p - i >= k) {
      k = p - i;
      r = i;
    }
  }
  cout << k << " " << r;
  return 0;
}
