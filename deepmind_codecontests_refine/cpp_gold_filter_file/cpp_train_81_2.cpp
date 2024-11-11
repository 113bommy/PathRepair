#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 5;

int lab[maxn], N;
int a[maxn], D;
vector<pair<ll, ii>> edge;

void init(int n)
{
  for(int i = 1; i <= n; ++i)
    lab[i] = -1;
}

int finds(int u)
{
  if(lab[u] < 0) return u;
  return lab[u] = finds(lab[u]);
}

bool merges(int u, int v)
{
  u = finds(u); v = finds(v);
  if(u == v) return false;
  if(lab[v] < lab[u]) swap(u, v);
  lab[u] += lab[v];
  lab[v] = u;
  return true;
}

void solve(int l, int r)
{
  if(l >= r) return;
  int mid = (l + r) / 2;
  solve(l, mid); solve(mid + 1, r);
  int minl = l, minr = mid + 1;
  for(int i = l; i <= mid; ++i)
    if(1ll * D * (mid - i) + a[i] < 1ll * D * (mid - minl) + a[minl])
      minl = i;
  for(int i = mid + 1; i <= r; ++i)
    if(1ll * D * (i - mid) + a[i] < 1ll * D * (minr - mid) + a[minr])
      minr = i;
  for(int i = l; i <= mid; ++i)
    edge.eb(1ll * D * (minr - i) + a[i] + a[minr], mp(i, minr));
  for(int i = mid + 1; i <= r; ++i)
    edge.eb(1ll * D * (i - minl) + a[i] + a[minl], mp(i, minl));
}

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  cin >> N >> D;
  for(int i = 1; i <= N; ++i)
    cin >> a[i];
  solve(1, N);
  init(N);
  sort(edge.begin(), edge.end());
  ll res = 0;
  for(auto & all : edge){
    if(merges(all.se.fi, all.se.se)){
      res += all.fi;
    }
  }
  cout << res;
}
