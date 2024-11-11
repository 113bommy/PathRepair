#include <bits/stdc++.h>
const int mod = 998244353;
int add(int a, int b) { return (a += b) >= mod ? a -= mod : a; }
int sub(int a, int b) { return add(a, mod - b); }
int mul(int a, int b) { return int(1LL * a * b % mod); }
struct State {
  int l, r, v;
  int sum() const { return mul(r - l + 1, v); }
};
int solve(const int k, const std::vector<int> &arr) {
  if (arr.empty()) {
    return 1;
  }
  std::vector<State> st;
  if (arr[0] == -1) {
    st.push_back(State{1, k, 1});
  } else {
    st.push_back(State{0, arr[0] - 1, 0});
    st.push_back(State{arr[0], arr[0], 1});
    st.push_back(State{arr[0] + 1, k + 1, 0});
  }
  int sum = 0;
  for (auto &s : st) {
    sum = add(sum, s.sum());
  }
  for (int i = 1; i < (int)arr.size(); ++i) {
    if (arr[i] == -1) {
      for (auto &s : st) {
        s.v = sub(sum, s.v);
      }
      sum = mul(sum, k - 1);
    } else {
      for (auto &s : st) {
        if (s.l <= arr[i] && arr[i] <= s.r) {
          State tmp = s;
          tmp.l = tmp.r = arr[i];
          tmp.v = sub(sum, tmp.v);
          sum = tmp.v;
          st.clear();
          st.push_back(State{0, tmp.l - 1, 0});
          st.push_back(tmp);
          st.push_back(State{tmp.r + 1, k + 1, 0});
          break;
        }
      }
    }
  }
  return sum;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  for (int n, k; std::cin >> n >> k;) {
    std::vector<int> fi, se;
    for (int i = 0, v; i < n; ++i) {
      std::cin >> v;
      if (i % 2 == 0) {
        fi.push_back(v);
      } else {
        se.push_back(v);
      }
    }
    std::cout << mul(solve(k, fi), solve(k, se)) << std::endl;
  }
  return 0;
}
