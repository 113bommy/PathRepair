#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) cin >> x;
  return in;
}
template <typename T>
ostream &operator<<(ostream &in, vector<T> &v) {
  for (auto &x : v) in << x << " ";
  return in;
}
long long fast(long long a, long long b, long long mid) {
  if (b == 0) return 1;
  a %= mid;
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % mid;
    }
    a *= a;
    a %= mid;
    b >>= 1;
  }
  return ans;
}
class solve {
 public:
  solve() {
    long long k, a, b;
    map<int, map<int, int>> Win;
    Win[2][1] = 1;
    Win[1][2] = 2;
    Win[1][0] = 1;
    Win[0][1] = 2;
    Win[0][2] = 1;
    Win[2][0] = 2;
    cin >> k >> a >> b;
    vector<vector<int>> w(3, vector<int>(3)), v(3, vector<int>(3));
    cin >> v >> w;
    int A = a, B = b;
    for (auto &x : v) {
      for (auto &y : x) --y;
    }
    for (auto &x : w) {
      for (auto &y : x) --y;
    }
    --a, --b;
    long long sa = 0, sb = 0, sc = 0;
    vector<pair<int, int>> Turn;
    map<pair<int, int>, vector<int>> M;
    while (sc < k) {
      if (M.find({a, b}) != M.end()) {
        long long dA = sa - M[{a, b}][0];
        long long dB = sb - M[{a, b}][1];
        long long dx = sc - M[{a, b}][2];
        sa += dA * ((k - sc) / dx) - Turn[sc - dx].first +
              Turn[sc - dx + (k - sc) % dx].first;
        sb += dB * ((k - sc) / dx) - Turn[sc - dx].second +
              Turn[sc - dx + (k - sc) % dx].second;
        break;
      } else {
        M[{a, b}] = {int(sa), int(sb), int(sc)};
        Turn.push_back({int(sa), int(sb)});
        if (Win[a][b] == 1) {
          sa++;
        } else if (Win[a][b] == 2)
          sb++;
        A = v[a][b];
        B = w[a][b];
        a = A;
        b = B;
      }
      ++sc;
    }
    cout << sa << " " << sb << endl;
  }
};
int32_t main() {
  int t = 1, i = 1;
  if (0) scanf("%d", &t);
  while (t--) {
    if (0) printf("Case #%d: ", i++);
    new solve;
  }
  return 0;
}
