#include <bits/stdc++.h>
using namespace std;
long long a, b, n, m, x, k, c, y, z, i, j, l, r, u, ans, sum, maxx,
    v[2555][2555], d;
long long na, ma, nb, mb;
long long br[1456789], ar[1456789], mn[1456789], mx[1456789], used[1456789],
    g[55][55];
char h[1234][1234], p[55][55];
string s, t, ress;
vector<long long> vec, as;
map<long long, long long> mmap;
set<long long> ss;
bool ok[1456789], oka[1456789];
char ch;
map<pair<int, int>, int> mpp;
void dii() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;
    ans += (c - a + 1) * (d - b + 1);
  }
  cout << ans;
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q = 1;
  while (q--) dii();
  return 0;
}
