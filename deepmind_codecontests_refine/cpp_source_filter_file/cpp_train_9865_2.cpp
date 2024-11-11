#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e9 + 7;
const long long INF = 1e18;
const double eps = 1e-6;
const double PI(acos(-1.0));
int n, k;
struct H {
  int s, c, id;
};
bool cmp(H a, H b) { return a.s < b.s; }
long long ans[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  vector<H> v(n);
  for (int i = 0; i < (n); i++) cin >> v[i].s;
  for (int i = 0; i < (n); i++) cin >> v[i].c, v[i].id = i;
  sort((v).begin(), (v).end(), cmp);
  set<int> q;
  long long tot = 0;
  int j = 0;
  for (int i = 0; i < (n); i++) {
    while (j < i && v[i].s > v[j].s) {
      q.insert(v[j].c);
      tot += v[j].c;
      if (((int)q.size()) > k) {
        tot -= *q.begin();
        q.erase(q.begin());
      }
      j++;
    }
    ans[v[i].id] = v[i].c + tot;
  }
  for (int i = 0; i < (n); i++) cout << ans[i] << " ";
}
