#include <bits/stdc++.h>
using namespace std;
long long int tc;
long long int N, A, R, M, th;
long long int n, i, j, t, y, flag, mid, l, d, r, k, g, m, ans, x, h, z, sum, q,
    pos;
multiset<long long int> ms;
map<long long int, long long int> tprev;
bool vis[200100] = {false};
vector<long long int> a;
vector<long long int> b;
deque<long long int> e;
vector<char> v;
vector<pair<long long int, long long int>> f;
char c;
map<long long int, long long int> mp;
set<long long int> s;
set<pair<long long int, long long int>> ns;
map<long long int, vector<long long int>> mpn;
vector<long long int> adj[200100];
vector<long long int> fi;
vector<long long int> la;
string st, ri, fans;
long long int cnt[200100] = {0};
long long int pre[200100] = {0};
const int MAX_L = 20;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
    b.push_back(0);
  }
  for (i = n - 2; i >= 0; i--) {
    a[i] += a[i + 1];
  }
  t = a[0];
  sort(a.begin() + 1, a.end());
  ans = 0;
  for (i = n - 1; i >= n - k + 1; i--) ans += a[i];
  ans += t;
  cout << ans;
  a.clear();
  b.clear();
  mp.clear();
  tprev.clear();
  cout << endl;
  return 0;
}
