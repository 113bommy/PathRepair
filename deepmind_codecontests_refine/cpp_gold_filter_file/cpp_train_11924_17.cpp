#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
vector<int> pos[MAXN];
vector<int> p;
int a[MAXN];
bool er[1005];
int main() {
  cin.sync_with_stdio(false);
  for (int i = 2; i < 1005; i++) {
    if (!er[i]) p.push_back(i);
    int k = 2 * i;
    while (k < 1005) {
      er[k] = true;
      k += i;
    }
  }
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    if (x < MAXN) {
      pos[x].push_back(i + 1);
    }
  }
  int ans = -1;
  int ansnum;
  for (int l = 1; l <= m; l++) {
    int ll = l;
    int pi = 0;
    vector<int> d;
    d.push_back(1);
    while (ll > 1 && pi < p.size()) {
      int cnt = 0;
      while (ll % p[pi] == 0) {
        ll /= p[pi];
        cnt++;
      }
      int s = d.size();
      int pow = 1;
      for (int j = 0; j < cnt; j++) {
        pow *= p[pi];
        for (int i = 0; i < s; i++) {
          d.push_back(d[i] * pow);
        }
      }
      pi++;
    }
    if (ll > 1) {
      int s = d.size();
      for (int i = 0; i < s; i++) {
        d.push_back(d[i] * ll);
      }
    }
    int res = 0;
    for (int i = 0; i < d.size(); i++) {
      res += pos[d[i]].size();
    }
    if (res > ans) {
      ans = res;
      ansnum = l;
    }
  }
  cout << ansnum << " " << ans << endl;
  vector<int> leet;
  for (int i = 0; i < n; i++) {
    if (ansnum % a[i] == 0) cout << i + 1 << " ";
  }
  return 0;
}
