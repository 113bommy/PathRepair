#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, 0};
long long int m = 0, n, res = 0, k, ans = 0;
string s2, ch = "", s, t, s1 = "";
vector<pair<string, long long int> > vm;
vector<pair<pair<long long int, long long int>, long long int> > vvv;
vector<pair<long long int, long long int> > vv;
vector<pair<string, long long int> > vv2;
set<long long int> v[200], v1;
long long int vis[105], a[105][105];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int i = 0, x = 0, z = 0, y = 0, j = 0, q, mx = 0, idx = 0, ok = 0,
                l = 0, r = 0, negatif = 0, positif = 0, l1, r1, d, p;
  set<pair<long long int, long long int> >::iterator itp;
  multiset<long long int>::iterator it;
  cin >> n;
  if (n == 1) return cout << "0", 0;
  if (n & 1)
    m = ((n + 1) / 2) * (n / 2);
  else
    m = (n * n) / 4;
  cout << m << endl;
  for (i = 1; i <= n / 2; i++) {
    for (j = (n / 2) + 1; j <= n; j++) cout << i << " " << j << endl;
  }
  return 0;
}
