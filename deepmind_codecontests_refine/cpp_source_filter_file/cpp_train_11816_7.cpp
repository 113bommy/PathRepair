#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
vector<pair<int, int> > v;
long long ways[2050], F[200005], Fi[200005];
long long po(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b % 2) r = r * a % M;
    a = a * a % M;
    b /= 2;
  }
  return r;
}
void pre() {
  F[0] = 1;
  for (long long i = 1; i < 200005; i++) {
    F[i] = F[i - 1] * i % M;
  }
  Fi[200001] = po(F[200001], M - 2);
  for (long long i = 200000; i >= 0; i--) {
    Fi[i] = Fi[i + 1] * (i + 1) % M;
  }
}
long long get_ways(int p, int q) {
  int x = v[q].first - v[p].first;
  int y = v[q].second - v[p].second;
  if (x < 0 || y < 0) return 0;
  long long res = F[x + y];
  res = res * Fi[x] % M;
  res = res * Fi[y] % M;
  return res;
}
int main() {
  int i, j, h, w, n, r, c;
  ios_base::sync_with_stdio(0);
  pre();
  cin >> h >> w >> n;
  v.push_back({1, 1});
  for (i = 1; i <= n; i++) {
    cin >> r >> c;
    v.push_back({r, c});
  }
  v.push_back({h, w});
  sort(v.begin(), v.end());
  for (i = 1; i <= n + 1; i++) {
    ways[i] = get_ways(0, i);
    for (j = 1; j < i; j++) {
      ways[i] = (ways[i] - ways[j] * get_ways(j, i) + M) % M;
    }
  }
  cout << ways[n + 1];
  return 0;
}
