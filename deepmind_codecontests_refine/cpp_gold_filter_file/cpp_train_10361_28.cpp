#include <bits/stdc++.h>
using namespace std;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
const int INF = 1 << 29;
template <typename T>
struct RangeMaxQuery {
  int N, _N;
  vector<T> dat;
  RangeMaxQuery(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N) N <<= 1;
    dat.assign(2 * N - 1, 0);
  }
  void update(int k, T val) {
    assert(0 <= k && k < _N);
    k += N - 1;
    dat[k] = val;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = max(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }
  T query(int a, int b) {
    assert(0 <= a && a <= b && b <= _N);
    return query(a, b, 0, 0, N);
  }
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return dat[k];
    int mid = (l + r) / 2;
    return max(query(a, b, 2 * k + 1, l, mid), query(a, b, 2 * k + 2, mid, r));
  }
};
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<pair<long long int, int>> cakes(N);
  for (int i = 0; i < (int)(N); i++) {
    long long int r, h;
    cin >> r >> h;
    cakes.emplace_back(r * r * h, -i);
  }
  sort(cakes.begin(), cakes.end());
  RangeMaxQuery<long long int> rmq(N);
  for (auto cake : cakes) {
    int idx = -cake.second;
    long long int vol = cake.first;
    rmq.update(idx, vol + rmq.query(0, idx));
  }
  cout << setprecision(20) << rmq.query(0, N) * acos(-1) << endl;
  return 0;
}
