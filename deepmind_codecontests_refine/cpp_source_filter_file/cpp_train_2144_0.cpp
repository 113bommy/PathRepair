#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T>;
template <typename T>
using dpair = pair<T, T>;
template <class T1, class T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  return is >> p.first >> p.second;
}
template <class T1, class T2>
void operator+=(vector<T1> &v, const T2 &obj) {
  v.push_back(obj);
}
template <class T1>
void operator+=(vector<T1> &v, const T1 &obj) {
  v.push_back(obj);
}
long long get_millis() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch())
      .count();
}
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3fll;
const long long mod = 1e9 + 7;
class range {
 public:
  range(int end) : _start(0), _end(end), _step(1) {}
  range(int start, int end) : _start(start), _end(end), _step(1) {}
  range(int start, int end, int step) : _start(start), _end(end), _step(step) {}
  class iterator {
   public:
    iterator(int v, range &par) : val(v), parent(par){};
    int operator*() const { return val; }
    int operator++() { return (val += parent._step); }
    bool operator==(const range::iterator &iter) const {
      if (&parent != &iter.parent) {
        return false;
      }
      if (val == iter.val) {
        return true;
      }
      if (parent._step > 0) {
        return val >= parent._end && iter.val >= parent._end;
      } else {
        return val <= parent._end && iter.val <= parent._end;
      }
    }
    bool operator!=(const range::iterator &iter) const {
      return !(this->operator==(iter));
    }

   private:
    int val;
    range &parent;
  };
  range::iterator begin() { return {_start, *this}; }
  range::iterator end() { return {_end, *this}; }

 protected:
  int _start, _end, _step;

 private:
};
const int MAXN = 90;
vector<dpair<int>> adj[MAXN];
int dp[2][MAXN][MAXN][MAXN];
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int N, K, M;
  cin >> N >> K >> M;
  K--;
  if (K == 0) {
    cout << 0;
    return 0;
  }
  for (int i : range(M)) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
  }
  memset(dp, INF, sizeof(dp));
  for (int a = 1; a <= N; a++) {
    dp[0][0][a][N + 1] = 0;
    dp[1][0][0][a] = 0;
  }
  for (int len = 1; len <= K; len++) {
    for (int l = 0; l < N; l++) {
      for (int r = l + 1; r <= N + 1; r++) {
        for (dpair<int> p : adj[l]) {
          if (p.first > l && p.first < r) {
            dp[0][len][p.first][r] =
                min(dp[0][len][p.first][r], dp[0][len - 1][l][r] + p.second);
            dp[1][len][l][p.first] =
                min(dp[1][len][l][p.first], dp[0][len - 1][l][r] + p.second);
          }
        }
        for (dpair<int> p : adj[r]) {
          if (p.first > l && p.first < r) {
            dp[1][len][l][p.first] =
                min(dp[1][len][l][p.first], dp[1][len - 1][l][r] + p.second);
            dp[0][len][p.first][r] =
                min(dp[0][len][p.first][r], dp[1][len - 1][l][r] + p.second);
          }
        }
      }
    }
  }
  int best = INF;
  for (int l = 0; l <= N; l++) {
    for (int r = l + 1; r <= N + 1; r++) {
      best = min(best, dp[0][K][l][r]);
      best = min(best, dp[1][K][l][r]);
    }
  }
  if (best == INF) {
    cout << -0.999999;
  } else {
    cout << best;
  }
}
