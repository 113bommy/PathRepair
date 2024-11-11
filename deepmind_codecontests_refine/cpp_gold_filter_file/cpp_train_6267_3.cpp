#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e17 + 696969;
long long n, total;
vector<long long> pos;
vector<long long> D[100011];
void get_div() {
  for (long long i = 2; i < 100011; i++) {
    for (long long j = i; j < 100011; j += i) D[j].push_back(i);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  get_div();
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (x > 0) {
      pos.push_back(i);
      total++;
    }
  }
  long long ans = INF;
  for (long long d : D[total]) {
    long long cost = 0, x = d / 2;
    for (long long i = 0; i < total; i++) {
      if (i > 0 and i % d == 0) x += d;
      long long dist = pos[i] - pos[x];
      if (dist < 0) dist = -dist;
      cost += dist;
    }
    ans = min(ans, cost);
  }
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}
