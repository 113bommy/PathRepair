#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
using namespace std;
const long long mod = 1000000007;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
const int mxN = 200010;
struct PT {
  long long x, y;
  PT operator-(PT o) { return PT{x - o.x, y - o.y}; }
  bool operator<(const PT& o) const {
    if (x != o.x) return x < o.x;
    return y < o.y;
  }
};
long long cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
PT conv(PT a) { return PT{a.x, a.y - a.x * a.x}; }
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<PT> ps(N);
  for (int i = 0; i < N; i++) {
    cin >> ps[i].x >> ps[i].y;
  }
  sort(begin(ps), end(ps));
  vector<PT> all;
  for (int i = 0, j = 0; i < N; i = j) {
    while (j < N && ps[j].x == ps[i].x) j++;
    all.push_back(ps[j - 1]);
  }
  reverse(all.begin(), all.end());
  vector<PT> res;
  for (int i = 0; i < (int)all.size(); i++) {
    while (res.size() >= 2 && cross(res.back() - res[res.size() - 2],
                                    all[i] - res[res.size() - 2]) < 0)
      res.pop_back();
    res.push_back(all[i]);
  }
  cout << res.size() - 1 << '\n';
  return 0;
}
