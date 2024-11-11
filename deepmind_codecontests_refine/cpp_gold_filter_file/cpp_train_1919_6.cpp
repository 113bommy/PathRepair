#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int N = 300005;
struct dupa {
  long long first, second, RD;
};
dupa make_pair(long long a, long long b, long long c) {
  dupa x;
  x.first = a;
  x.second = b;
  x.RD = c;
  return x;
}
dupa operator+(const dupa &a, const dupa &b) {
  return make_pair((a.first + b.first) % MOD, (a.second + b.second) % MOD,
                   (a.RD + b.RD) % MOD);
}
struct node {
  vector<long long> v;
  int parent, depth, subtree, super_parent, pos, num;
};
node tab[N];
bool cmp_subtree(const int &a, const int &b) {
  return tab[a].subtree > tab[b].subtree;
}
void dfs(int a) {
  tab[a].subtree = 1;
  for (__typeof((tab[a].v).begin()) it = ((tab[a].v).begin());
       it != (tab[a].v).end(); ++it) {
    tab[*it].depth = tab[a].depth + 1;
    dfs(*it);
    tab[a].subtree += tab[*it].subtree;
  }
  if (!tab[a].v.empty()) {
    sort((tab[a].v).begin(), (tab[a].v).end(), cmp_subtree);
    int b = tab[a].v[0];
    tab[b].super_parent = a;
  }
}
int NUMER = 1;
int rozmiar[N], pierwszy[N];
vector<dupa> dp[N];
void dfs2(int a) {
  for (__typeof((tab[a].v).begin()) it = ((tab[a].v).begin());
       it != (tab[a].v).end(); ++it) {
    if (a == tab[*it].super_parent) {
      tab[*it].num = tab[a].num;
      tab[*it].pos = tab[a].pos + 1;
    } else {
      NUMER++;
      tab[*it].num = NUMER;
      tab[*it].pos = 0;
      pierwszy[NUMER] = *it;
    }
    rozmiar[tab[*it].num]++;
    dfs2(*it);
  }
}
void wstaw(int a, long long x, long long k) {
  int num = tab[a].num;
  int pos = tab[a].pos + rozmiar[num];
  long long dep = tab[a].depth;
  dupa y = make_pair(x, k, k * dep);
  while (pos > 0) {
    dp[num][pos] = dp[num][pos] + y;
    pos /= 2;
  }
}
long long zapytaj(int a, long long dep) {
  int num = tab[a].num;
  int pocz = rozmiar[num], kon = tab[a].pos + rozmiar[num];
  dupa res = make_pair(0, 0, 0);
  res = res + dp[num][pocz];
  if (pocz != kon) res = res + dp[num][kon];
  while (pocz / 2 != kon / 2) {
    if (pocz % 2 == 0) res = res + dp[num][pocz ^ 1];
    if (kon % 2) res = res + dp[num][kon ^ 1];
    pocz /= 2;
    kon /= 2;
  }
  long long wyn = (res.first - dep * res.second + res.RD) % MOD;
  if (wyn < 0) wyn += MOD;
  a = pierwszy[num];
  if (tab[a].parent == 0) return wyn;
  return (wyn + zapytaj(tab[a].parent, dep)) % MOD;
}
void jebaj() {
  int n;
  cin >> n;
  for (int i = (0); i <= ((n - 1) - 1); ++i) {
    int a;
    cin >> a;
    tab[a].v.push_back(i + 2);
    tab[i + 2].parent = a;
  }
  dfs(1);
  tab[1].pos = 0;
  tab[1].num = 1;
  rozmiar[1] = 1;
  pierwszy[1] = 1;
  dfs2(1);
  dupa zero = make_pair(0, 0, 0);
  for (int i = (1); i <= (NUMER); ++i) {
    int a = 1;
    while (a <= rozmiar[i]) a *= 2;
    for (int j = (0); j <= ((2 * a) - 1); ++j) dp[i].push_back(zero);
    rozmiar[i] = a;
  }
  int q;
  cin >> q;
  for (int i = (0); i <= ((q)-1); ++i) {
    int a, b, c, d;
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      wstaw(b, c, d);
    }
    if (a == 2) {
      cin >> b;
      cout << zapytaj(b, tab[b].depth) << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  t = 1;
  for (int i = (0); i <= ((t)-1); ++i) {
    jebaj();
  }
}
