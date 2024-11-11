#include <bits/stdc++.h>
using namespace std;
const long long int inf = 9e18;
const long double pi = 2 * acos(0.0);
long long int tes, n, root, dis_bet_them, curr_dis, curr, b;
vector<long long int> edges[1001], arr[1001], brr[1001];
string s;
long long int power(long long int x, long long int y) {
  long long int res = 1ll;
  while (y > 0) {
    if (y & 1) res = res * x;
    y >>= 1;
    x = x * x;
  }
  return res;
}
void dfs(long long int x, long long int par, long long int dis) {
  arr[dis].push_back(x);
  ;
  for (int i = 0; i < (int)((edges[x]).size()); i++) {
    if (edges[x][i] == par) continue;
    dfs(edges[x][i], x, dis + 1);
  }
}
void dfs1(long long int x, long long int par, long long int dis) {
  brr[dis].push_back(x);
  ;
  for (int i = 0; i < (int)((edges[x]).size()); i++) {
    if (edges[x][i] == par) continue;
    dfs1(edges[x][i], x, dis + 1);
  }
}
void solve() {
  cin >> n;
  ;
  for (int i = 0; i < 1001; i++)
    edges[i].clear(), arr[i].clear(), brr[i].clear();
  ;
  for (int i = 0; i < n - 1; i++) {
    long long int x, y;
    cin >> x >> y;
    x--, y--;
    edges[x].push_back(y), edges[y].push_back(x);
  }
  cout << "? " << n << " ";
  ;
  for (int i = 1; i < n + 1; i++) cout << i << " ";
  cout.flush();
  cin >> root >> dis_bet_them;
  root--;
  dfs(root, -1, 0);
  long long int l = 0, r = n + 1, last = root;
  while (r >= l) {
    long long int mid = (l + r) / 2;
    if ((int)((arr[mid]).size()) == 0)
      r = mid - 1;
    else {
      cout << "? " << (int)((arr[mid]).size()) << " ";
      ;
      for (int i = 0; i < (int)((arr[mid]).size()); i++)
        cout << arr[mid][i] + 1 << " ";
      cout.flush();
      cin >> curr >> curr_dis;
      if (curr_dis == dis_bet_them)
        last = curr - 1, l = mid + 1;
      else
        r = mid - 1;
    }
  }
  dfs1(last, -1, 0);
  cout << "? " << (int)((brr[dis_bet_them]).size()) << " ";
  ;
  for (int i = 0; i < (int)((brr[dis_bet_them]).size()); i++)
    cout << brr[dis_bet_them][i] + 1 << " ";
  cout.flush();
  cin >> b >> curr;
  cout << "! " << last + 1 << " " << b << "\n";
  cout.flush();
  cin >> s;
  if (s == "Incorrect") tes = 0;
}
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> tes;
  while (tes--) {
    solve();
  }
}
