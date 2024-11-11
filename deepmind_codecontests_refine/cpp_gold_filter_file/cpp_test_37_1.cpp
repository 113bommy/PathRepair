#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int N = 300001;
int parent[N];
int rnk[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int zz = 0; zz < t; zz++) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> e;
    set<int> v;
    for (int i = 0; i < n; i++) v.insert(i);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      c--;
      v.erase(b);
    }
    int kek = *(v.begin());
    for (int i = 0; i < n; i++)
      if (i != kek) cout << i + 1 << " " << kek + 1 << "\n";
  }
}
