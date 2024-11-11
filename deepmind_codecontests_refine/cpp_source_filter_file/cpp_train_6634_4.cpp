#include <bits/stdc++.h>
using namespace std;
class Timer {
 private:
  string scope_name;
  chrono::high_resolution_clock::time_point start_time;

 public:
  Timer(string name) : scope_name(name) {
    start_time = chrono::high_resolution_clock::now();
  }
  ~Timer() {
    auto stop_time = chrono::high_resolution_clock::now();
    auto length =
        chrono::duration_cast<chrono::microseconds>(stop_time - start_time)
            .count();
    double mlength = double(length) * 0.001;
    ;
  }
};
const long long MOD = 1000000007;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
const long long MAXN = 100005;
long long n;
vector<pair<long long, long long> > v;
struct Vec {
  long long x, y, id;
  array<pair<int, int>, 2> child;
};
vector<Vec> vec;
bool valid(int i, int j) {
  for (auto s1 : {-1, 1}) {
    for (auto s2 : {-1, 1}) {
      long long a =
          ((vec[i].x * s1 + vec[j].x * s2) * (vec[i].x * s1 + vec[j].x * s2)) +
          ((vec[i].y * s1 + vec[j].y * s2) * (vec[i].y * s1 + vec[j].y * s2));
      if (a <= 1000000000000LL) {
        array<pair<int, int>, 2> c = {pair<int, int>(i, s1),
                                      pair<int, int>(j, s2)};
        vec.push_back({vec[i].x * s1 + vec[j].x * s2,
                       vec[i].y * s1 + vec[j].y * s2, -1, c});
        return true;
      }
    }
  }
  return false;
}
int ans[MAXN];
void dfs(int i, int s) {
  if (vec[i].id != -1) {
    ans[vec[i].id] = s;
  } else {
    for (auto p : vec[i].child) {
      dfs(p.first, p.second * s);
    }
  }
}
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i += 1) {
    long long x, y;
    cin >> x >> y;
    vec.push_back({x, y, i, array<pair<int, int>, 2>()});
  }
  if (n <= 2) {
    for (int i = 0; i < n; i += 1) {
      cout << 1 << " \n"[i == n - 1];
    }
    return 0;
  }
  int f = 0, s = 1;
  for (int i = 2; i < n; i++) {
    if (valid(f, i)) {
      f = int(vec.size()) - 1;
      continue;
    } else if (valid(s, i)) {
      s = int(vec.size()) - 1;
      continue;
    } else if (valid(s, f)) {
      s = int(vec.size()) - 1;
      f = i;
    } else {
      assert(false);
    }
  }
  long long tx = vec[f].x + vec[s].x;
  long long ty = vec[f].y + vec[s].y;
  dfs(f, ((tx) * (tx)) + ((ty) * (ty)) <= 1000000000000LL ? 1 : -1);
  dfs(s, 1);
  long long ux = 0, uy = 0;
  for (int i = 0; i < n; i += 1) {
    ux += vec[i].x * ans[i];
    uy += vec[i].y * ans[i];
    cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}
