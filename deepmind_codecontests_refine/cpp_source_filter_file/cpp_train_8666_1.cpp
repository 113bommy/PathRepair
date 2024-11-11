#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265359;
long long inf = 4000000000000000000LL;
long long modulo = pow(10, 9) + 7;
double eps = 1e-6;
const long long mod = 1000000007;
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
const long long N = 1000050;
const long long sz = (long long)1000000 + 80;
long long S[sz * 4], mx[sz * 4];
long long Q;
int k, pref[N], mini = 25, maxi = -5, ind = 1, r, a, b, z, d, g, m, ans = 0,
                cem = 0, t = 1, last = 0, l, c, x1, x2;
string he = "YES", yox = "NO";
vector<int> adj[1050], mesafe[2000];
vector<long long> visited, pisited;
vector<long long> distances;
void dfs(int node, int mesafe, int parent) {
  int sum = 0;
  for (int i = 0; i < (long long)(adj[node].size()); ++i) {
    ind = adj[node][i];
    if (ind != parent) dfs(ind, mesafe + 1, node);
  }
  distances[node] = mesafe + 1;
}
int main() {
  cin >> t;
  int r = -1, a, b, k, l1, l2, r1, r2, n;
  while (t--) {
    cin >> n;
    vector<pair<long long, long long> > agac(n, {0, 0});
    distances.clear();
    for (int i = 0; i < n + 2; i++)
      adj[i].clear(), distances.push_back(0), mesafe[i].clear();
    for (int n1 = 0; n1 < n - 1; ++n1) cin >> agac[n1].first >> agac[n1].second;
    cout << "? " << n << ' ';
    for (int i = 1; i <= n; i++) {
      cout << i << ' ';
    }
    cout << "\n";
    int root, neqeder;
    cin >> root >> neqeder;
    root--;
    for (int i1 = 0; i1 < n - 1; ++i1)
      adj[agac[i1].second - 1].push_back(agac[i1].first - 1),
          adj[agac[i1].first - 1].push_back(agac[i1].second - 1);
    dfs(root, -1, root);
    for (int zo = 0; zo < n; zo++) mesafe[distances[zo]].push_back(zo);
    int left = max(neqeder / 2 - 3, 0), right = n - 1;
    int neqeder1, root1 = root + 1;
    while (left < right - 1) {
      int mid = (left + right + 1) / 2;
      if ((long long)(mesafe[mid].size()) == 0) {
        right = mid - 1;
        continue;
      }
      cout << "? " << (long long)(mesafe[mid].size()) << ' ';
      for (int i : mesafe[mid]) cout << i + 1 << ' ';
      cout << "\n";
      cin >> root >> neqeder1;
      if (neqeder1 == neqeder)
        left = mid, root1 = root;
      else
        right = mid - 1;
    }
    root1--;
    for (int i = 0; i < n + 2; i++) mesafe[i].clear();
    distances.clear();
    dfs(root1, -1, root1);
    for (int zo = 0; zo < n; zo++) mesafe[distances[zo]].push_back(zo);
    cout << "? " << (long long)(mesafe[neqeder].size()) << ' ';
    for (int i : mesafe[neqeder]) cout << i + 1 << ' ';
    cout << "\n";
    cin >> root >> neqeder1;
    if (root == -1) return 0;
    cout << "! " << root << ' ' << root1 + 1 << "\n";
    string str;
    cin >> str;
    if (str == "Incorrect") return 0;
  }
  return 0;
}
