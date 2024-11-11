#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long int rand(long long int x, long long int y) {
  ++y;
  return (rng() % (y - x)) + x;
}
string to_string(char c) {
  string second(1, c);
  return second;
}
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void degug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void degug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  degug_out(T...);
}
inline long long int gcd(long long int a, long long int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
int n, m, C[(300006 / 3)];
int A[(300006 / 3)];
int P[(300006 / 3)];
pair<long long int, long long int> micost[(1 << 10)][2];
void offset(int pos, int bm, long long int cost, long long int i) {
  if (bm != 0 && micost[bm][0].second != i && micost[bm][1].second != i) {
    micost[bm][1] =
        min(micost[bm][1], pair<long long int, long long int>(cost, i));
    if (micost[bm][1] < micost[bm][0]) swap(micost[bm][0], micost[bm][1]);
  }
  if (pos == 9) return;
  if (bm & (1 << pos)) offset(pos + 1, bm ^ (1 << pos), cost, i);
  offset(pos + 1, bm, cost, i);
}
long long int help[(1 << 10)];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long int i = 0; i < (long long int)(1 << 10); ++i)
    micost[i][0] = micost[i][1] =
        pair<long long int, long long int>(((long long)1e18), -1);
  for (long long int i = 0; i < (long long int)n; ++i) {
    long long int x;
    cin >> x;
    for (long long int j = 0; j < (long long int)x; ++j) {
      long long int b;
      cin >> b;
      --b;
      A[i] += (1 << b);
    }
  }
  for (long long int bm = 0; bm < (long long int)(1 << 9); ++bm) {
    for (long long int i = 0; i < (long long int)n; ++i) {
      bool no = 0;
      for (long long int b = 0; b < (long long int)9; ++b) {
        if ((1 << b) & A[i])
          if (((1 << b) & bm) == 0) no = 1;
      }
      if (no) continue;
      help[bm]++;
    }
  }
  for (long long int i = 0; i < (long long int)m; ++i) {
    cin >> C[i];
    long long int x;
    cin >> x;
    for (long long int j = 0; j < (long long int)x; ++j) {
      long long int b;
      cin >> b;
      --b;
      P[i] += (1 << b);
    }
  }
  for (long long int i = 0; i < (long long int)m; ++i) {
    offset(0, P[i], C[i], i);
    micost[0][1] =
        min(micost[0][1], pair<long long int, long long int>(C[i], i));
    if (micost[0][1] < micost[0][0]) swap(micost[0][0], micost[0][1]);
  }
  pair<long long int, long long int> ans =
      pair<long long int, long long int>(-1, 0);
  pair<long long int, long long int> w =
      pair<long long int, long long int>(-2, -2);
  for (long long int bm = 0; bm < (long long int)(1 << 9); ++bm) {
    for (long long int p = 0; p < (long long int)m; ++p) {
      if ((bm | P[p]) > bm) continue;
      long long int res = bm;
      res ^= P[p];
      pair<long long int, long long int> xd =
          (micost[res][0].second == p ? micost[res][1] : micost[res][0]);
      if (0) cerr << res << ' ' << xd.second << '\n';
      if (xd.second == -1) continue;
      if (pair<long long int, long long int>(help[bm], -xd.first - C[p]) >
          ans) {
        ans = pair<long long int, long long int>(help[bm], -xd.first - C[p]);
        w = pair<long long int, long long int>(xd.second, p);
      }
    }
  }
  if (ans.first == -1) {
    assert(micost[0][0].second != -1 && micost[0][1].second != -1);
    cout << micost[0][0].second + 1 << ' ' << micost[0][1].second + 1 << '\n';
    return 0;
  }
  cout << w.first + 1 << ' ' << w.second + 1 << '\n';
}
