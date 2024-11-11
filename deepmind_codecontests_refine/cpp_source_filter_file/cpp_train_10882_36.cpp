#include <bits/stdc++.h>
using namespace std;
const int OO = 0xfffffff;
const int _OO = -1 * OO;
const double EPS = (1e-9);
const double pi = 3.14159265;
using namespace std;
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy8[8] = {1, -1, 0, 1, -1, 1, -1, 0};
const int N = 44724 + 50;
map<long long, bool> vis;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long a[n];
  for (int i = 0; i < (int)(n); ++i) cin >> a[i], vis[a[i]] = 1;
  vector<int> v;
  for (int i = 1; i < N; i++) {
    if (!vis[i] && m - i >= 0) {
      m -= i;
      v.push_back(i);
      vis[i] = 1;
    }
    if (m - i <= 0) break;
  }
  cout << ((int)((v).size())) << endl;
  for (auto i : v) cout << i << " ";
  return 0;
}
