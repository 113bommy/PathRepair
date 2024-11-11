#include <bits/stdc++.h>
using namespace std;
map<pair<long long, int>, pair<long long, int> > vis;
pair<long long, int> go(long long n, int m) {
  pair<long long, int> state(n, m);
  if (vis.count(state)) return vis[state];
  long long ret = 0;
  while (1) {
    long long p = 1;
    while (n / p >= 10) p *= 10;
    int d = n / p;
    int nm = max(m, d);
    pair<long long, int> aux = go(n % p, nm);
    ret += aux.first;
    n -= n % p;
    if (aux.second)
      n -= aux.second;
    else {
      n -= nm;
      ret++;
    }
    pair<long long, int> child(n, nm);
    if (vis.count(child))
      return vis[state] = pair<long long, int>(vis[child].first + ret,
                                               vis[child].second);
  }
}
int main() {
  long long n;
  cin >> n;
  for (int i = 0; i < 10; i++)
    vis[pair<long long, int>(0, i)] = pair<long long, int>(0, 0);
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      vis[pair<long long, int>(i, j)] = pair<long long, int>(1, max(0, j - i));
  cout << go(n, 0).first << endl;
  return 0;
}
