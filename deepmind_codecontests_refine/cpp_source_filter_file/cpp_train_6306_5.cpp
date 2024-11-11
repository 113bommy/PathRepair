#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
int fen[MAX_N];
void update(int x) {
  for (x++; x < MAX_N; x += x & -x) fen[x]++;
}
int get(int x) {
  int res = 0;
  for (x++; x; x -= x & -x) res += fen[x];
  return res;
}
int get(int lo, int hi) {
  if (lo > hi) return 0;
  return get(hi) - get(lo - 1);
}
pair<int, int> F[MAX_N];
pair<int, int> R[MAX_N];
int N, K;
int lb(int f, int x) { return lower_bound(F, F + N, make_pair(f, x)) - F; }
int ub(int f, int x) { return upper_bound(F, F + N, make_pair(f, x)) - F; }
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin >> N >> K;
  vector<pair<int, int>> ff(N);
  for (int i = 0; i < N; ++i) {
    int x, r, f;
    cin >> x >> r >> f;
    F[i].first = f;
    F[i].second = x;
    ff[i].first = f;
    ff[i].second = x;
    R[i].first = r;
    R[i].second = i;
  }
  sort(F, F + N);
  sort(R, R + N, greater<pair<int, int>>());
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int id = R[i].second;
    for (int f = -K; f <= K; ++f) {
      res += get(lb(ff[id].first + f, ff[id].second - R[i].first),
                 ub(ff[id].first + f, ff[id].second + R[i].first) - 1);
    }
    update(lb(ff[id].first, ff[id].second));
  }
  cout << res << endl;
  return 0;
}
