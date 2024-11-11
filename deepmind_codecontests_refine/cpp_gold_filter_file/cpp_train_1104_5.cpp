#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> pai) {
  return os << pai.first << ' ' << pai.second;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
  cout << '[';
  for (int i = 0, _i = (((int)(v).size())); i < _i; i++) cout << v[i] << ",";
  cout << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> v) {
  cout << "{";
  for (auto p : v) cout << p << ",";
  cout << "}";
  return os;
}
template <typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> v) {
  cout << "{";
  for (auto p : v) cout << p << ",";
  cout << "}";
  return os;
}
template <typename T>
void umax(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void umin(T &a, T b) {
  a = min(a, b);
}
int N;
long long dp1[11][100][3000];
long long dp2[11][100][3000];
int mlog(int b, long long v) {
  int ret = 0;
  long long c = 1;
  while (c > 0 and c <= v) c *= b, ret++;
  return ret;
}
long long get(int b, long long v) {
  long long c = v;
  vector<int> nums;
  while (v > 0) {
    nums.push_back(v % b);
    v /= b;
  }
  reverse(nums.begin(), nums.end());
  long long ret = 0;
  long long msk = 0;
  for (int i = 0, _i = (((int)(nums).size())); i < _i; i++) {
    for (int j = 0, _j = (nums[i]); j < _j; j++) {
      if (i > 0 or j > 0)
        0, ret += dp2[b][((int)(nums).size()) - i - 1][msk ^ (1 << j)];
      else
        for (int j = 1, _j = (((int)(nums).size()) - 1); j <= _j; j++)
          ret += dp1[b][j][0];
    }
    msk ^= (1 << nums[i]);
  }
  if (c > 0 and msk == 0) ret++;
  0;
  return ret;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  for (int b = (2), _b = (11); b < _b; b++) {
    dp1[b][0][0] = 1;
    dp2[b][0][0] = 1;
    for (int c = 1, _c = (mlog(b, 1e18)); c <= _c; c++)
      for (int d = 0, _d = (1 << b); d < _d; d++)
        for (int e = 0, _e = (b); e < _e; e++) {
          dp1[b][c][d] += e ? dp2[b][c - 1][d ^ (1 << e)] : 0;
          dp2[b][c][d] += dp2[b][c - 1][d ^ (1 << e)];
        }
  }
  0;
  cin >> N;
  for (int i = 0, _i = (N); i < _i; i++) {
    int b;
    long long l, r;
    cin >> b >> l >> r;
    cout << get(b, r) - get(b, l - 1) << '\n';
  }
}
