#include <bits/stdc++.h>
using namespace std;
int const INF = (int)1e9 + 1e3;
long long const INFL = (long long)1e18 + 1e6;
mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> ll_distr;
long long rnd(long long a, long long b) {
  return ll_distr(tw) % (b - a + 1) + a;
}
int is_prime(int num) {
  if (num == 1) {
    return false;
  }
  for (int i = 2; i * i <= num; ++i) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  int cnt[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    cnt[num - 1]++;
  }
  int mem[2] = {cnt[0], cnt[1]};
  vector<int> order;
  int ans = 0;
  vector<vector<int>> moves_vars = {{0}, {0, 0, 0}, {1, 0}};
  for (vector<int> moves : moves_vars) {
    int cur_ans = 0;
    vector<int> cur_order;
    for (int i = 0; i < 2; ++i) {
      cnt[i] = mem[i];
    }
    int cur = 0;
    for (int num : moves) {
      if (cnt[num] == 0) {
        continue;
      }
      cur += num + 1;
      if (is_prime(cur)) {
        ++cur_ans;
      }
      cnt[num]--;
      cur_order.push_back(num);
    }
    while (cnt[1]) {
      cur += 2;
      if (is_prime(cur)) {
        ++cur_ans;
      }
      --cnt[1];
      cur_order.push_back(1);
    }
    while (cnt[0] >= 2) {
      cur += 2;
      if (is_prime(cur)) {
        ++cur_ans;
      }
      cnt[0] -= 2;
      cur_order.push_back(0);
      cur_order.push_back(0);
    }
    if (cnt[0]) {
      cur_order.push_back(0);
    }
    if (ans < cur_ans) {
      ans = cur_ans;
      order = cur_order;
    }
  }
  for (int num : order) {
    cout << num + 1 << " ";
  }
  cout << "\n";
}
int main() {
  cout << setprecision(15) << fixed;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_count = 1;
  for (int test = 1; test <= test_count; ++test) {
    solve();
  }
}
