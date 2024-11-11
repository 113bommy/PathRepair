#include <bits/stdc++.h>
using namespace std;
using Long = int64_t;
constexpr Long Z = 0;
bool fire(Long N, Long M, int K, const vector<Long>& X, const vector<Long>& Y,
          Long t) {
  map<Long, int> xs;
  map<Long, int> ys;
  xs[0] = 0;
  xs[N] = 0;
  ys[0] = 0;
  ys[M] = 0;
  for (int i = 0; i < K; ++i) {
    Long x = X[i];
    Long y = Y[i];
    xs[max(x - t, Z)] = 0;
    xs[min(x + 1 + t, N)] = 0;
    ys[max(y - t, Z)] = 0;
    ys[min(y + 1 + t, M)] = 0;
  }
  int i = 0;
  for (auto& p : xs) {
    p.second = i++;
  }
  i = 0;
  for (auto& p : ys) {
    p.second = i++;
  }
  int nx = (int)xs.size();
  int ny = (int)ys.size();
  vector<vector<bool>> mat(ny + 1, vector<bool>(nx + 1));
  for (int i = 0; i < K; ++i) {
    Long x = X[i];
    Long y = Y[i];
    int bx = xs[max(x - t, Z)];
    int ex = xs[min(x + 1 + t, N)];
    int by = ys[max(y - t, Z)];
    int ey = ys[min(y + 1 + t, M)];
    for (int y = by; y < ey; ++y)
      for (int x = bx; x < ex; ++x) mat[y][x] = 1;
  }
  int bx = -1;
  int ex = -1;
  int by = -1;
  int ey = -1;
  for (int y = 0; y < ny - 1; ++y) {
    for (int x = 0; x < nx - 1; ++x) {
      if (mat[y][x]) continue;
      if (bx == -1) {
        bx = x;
        ex = x + 1;
        by = y;
        ey = y + 1;
      } else {
        bx = min(bx, x);
        ex = max(ex, x + 1);
        by = min(by, y);
        ey = max(ey, y + 1);
      }
    }
  }
  if (bx == -1) return true;
  Long bxx = 0, exx = N, byy = 0, eyy = M;
  for (const auto& p : xs) {
    if (p.second == bx) bxx = p.first;
    if (p.second == ex) exx = p.first;
  }
  for (const auto& p : ys) {
    if (p.second == by) byy = p.first;
    if (p.second == ey) eyy = p.first;
  }
  if (exx - bxx > 2 * t + 1 || eyy - byy > 2 * t + 1) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long N, M;
  int K;
  cin >> N >> M >> K;
  vector<Long> X(K), Y(K);
  for (int i = 0; i < K; ++i) {
    cin >> X[i] >> Y[i];
    --X[i];
    --Y[i];
  }
  Long lb = 0;
  Long ub = max(N, M);
  while (ub - lb >= 2) {
    Long mid = (ub + lb) / 2;
    if (fire(N, M, K, X, Y, mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  cout << ub << '\n';
  return 0;
}
