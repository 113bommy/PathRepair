#include <bits/stdc++.h>
using namespace std;
vector<int> v1, v2;
int act[100010];
int d, b, n;
int greedy(vector<int>& v, int l) {
  int wa(0), crn(0);
  for (int i(1); i <= l; i++) {
    crn += v[i];
    if (crn >= b)
      crn -= b;
    else
      wa++;
  }
  return wa;
}
pair<int, int> cbin(int x) {
  v1 = vector<int>(n + 1), v2 = vector<int>(n + 1);
  for (int i(1), copii(0), camera(1); copii < x; i++) {
    int moves = min(x - copii, act[i]);
    if (i > camera * d + camera) camera++;
    v1[camera] += moves;
    copii += moves;
  }
  for (int i(n), copii(0), camera(1); copii < (n - x); i--) {
    int moves = min((n - x) - copii, act[i]);
    if ((n - i + 1) > camera * d + camera) camera++;
    v2[camera] += moves;
    copii += moves;
  }
  int a = greedy(v1, (n + 1) / 2), b = greedy(v2, n / 2);
  return {a, b};
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d >> b;
  for (int i(1); i <= n; i++) cin >> act[i];
  int p(0), q(1 << 30), best(1e9);
  while (q) {
    if (p + q <= n * b) {
      auto x = cbin(p + q);
      best = min(best, max(x.first, x.second));
      if (x.first >= x.second) p += q;
    }
    q /= 2;
  }
  cout << best << '\n';
  return 0;
}
