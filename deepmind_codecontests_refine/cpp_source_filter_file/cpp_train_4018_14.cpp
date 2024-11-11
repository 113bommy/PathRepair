#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node {
  int banfcc;
  int t;
};
queue<node> q;
vector<int> v;
map<pair<int, int>, int> mp;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  node now, nxt;
  now.banfcc = now.t = 0;
  q.push(now);
  int cnt = 0;
  if (n == 0) {
    if (v[0] == 0)
      printf("1\n");
    else
      printf("-1\n");
    return 0;
  }
  int t = 0;
  while (!q.empty()) {
    now = q.front();
    q.pop();
    nxt.t = now.t + 1;
    for (int i = 0; i < v.size(); i++) {
      nxt.banfcc = now.banfcc + v[i];
      if (nxt.banfcc / n < nxt.t) continue;
      if (mp[make_pair(nxt.banfcc, nxt.t)]) continue;
      mp[make_pair(nxt.banfcc, nxt.t)] = 1;
      if (nxt.banfcc / n == nxt.t && nxt.banfcc % n == 0) {
        printf("%d\n", nxt.t);
        return 0;
      }
      q.push(nxt);
    }
    t++;
    if (t > 100000) break;
  }
  cout << -1 << endl;
  return 0;
}
