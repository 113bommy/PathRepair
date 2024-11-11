#include <bits/stdc++.h>
using namespace std;
long long a[(200020)];
vector<long long> ans;
struct node {
  long long v, i;
  bool operator<(const node& o) const { return v < o.v; }
};
vector<node> nodes;
long long v[(200020)];
signed main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  if (n == 1) {
    printf("%lld\n", a[1]);
    return 0;
  }
  if (n == 2) {
    printf("%lld\n", -a[1] - a[2]);
    return 0;
  }
  for (long long i = 1; i <= n; i++) {
    nodes.push_back((node){a[i], i});
  }
  sort(nodes.begin(), nodes.end());
  long long p = -1, cnt = 0;
  long long tot = 0, maxtot = 0;
  for (long long i = 1; i <= n; i++) tot += a[i];
  if (n % 3 == 1) {
    p = 0, cnt = 1;
    ans.push_back(tot);
    maxtot = tot;
  }
  for (long long i = 0, sz = nodes.size(); i < sz; i++) {
    tot -= nodes[i].v * 2;
    if ((n + i + 1) % 3 == 1) {
      if (-1 == p || tot > maxtot) {
        p = i + 1, cnt = 1;
        maxtot = tot;
      } else if (tot == maxtot) {
        cnt++;
      }
      ans.push_back(tot);
    }
  }
  for (long long i = 0; i < p; i++) {
    v[nodes[i].i] = 1;
  }
  long long ok = 0;
  for (long long i = 1; i < n; i++) {
    if ((v[i] ^ v[i + 1]) != 1) {
      ok = 1;
      break;
    }
  }
  if (cnt > 1 || ok) {
    printf("%lld\n", maxtot);
    return 0;
  }
  long long premaxtot = maxtot;
  maxtot += nodes[p].v * 2;
  maxtot -= nodes[p + 1].v * 2;
  for (long long i = 0, sz = ans.size(); i < sz; i++)
    if (ans[i] != premaxtot) {
      maxtot = max(maxtot, ans[i]);
    }
  cout << maxtot << endl;
  return 0;
}
