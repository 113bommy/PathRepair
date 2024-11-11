#include <bits/stdc++.h>
const int Inf = 2e9;
long long LINF = (long long)4e18;
using namespace std;
long long mod = 1e9 + 7;
bool cmp(vector<int> a, vector<int> b) { return a.size() < b.size(); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> vc(m + 1, 0);
  map<int, int> mp;
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    mp[q]++;
    vc[mp[q]]++;
    if (vc[mp[q]] == n)
      cout << 1;
    else
      cout << 0;
  }
  return 0;
}
