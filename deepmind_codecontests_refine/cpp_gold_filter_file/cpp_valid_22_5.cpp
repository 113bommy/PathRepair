#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> indices(k);
  for (int i = 0; i < k; i++) {
    int q;
    cin >> q;
    while (q--) {
      int x;
      cin >> x;
      indices[i].push_back(x - 1);
    }
    sort(indices[i].begin(), indices[i].end());
  }
  if (n == 1) {
    cout << "ACCEPTED\n";
    return 0;
  }
  vector<int> have(k);
  vector<ll> already(k);
  vector<int> first(n, -1);
  for (int i = 0; i < k; i++) {
    for (auto index : indices[i]) {
      if (first[index] == -1) {
        first[index] = i;
        have[i] += 1;
      } else {
        already[i] |= (1LL << index);
      }
    }
  }
  auto bad = [&]() -> void {
    cout << "REJECTED\n";
    exit(0);
  };
  for (int i = 0; i < n; i++) {
    if (first[i] == -1) {
      bad();
    }
  }
  set<ll> good;
  for (int zero = 0; zero <= n; zero++) {
    ll x = (1LL << n) - 1;
    ll y = (1LL << (n - zero)) - 1;
    good.insert(x - y);
  }
  ll value = 1;
  function<void(int)> dfs = [&](int depth) -> void {
    if (depth == k) {
      if (!good.count(value)) {
        bad();
      }
      return;
    }
    int base_one = __builtin_popcountll(value & already[depth]);
    int base_zero = (int)indices[depth].size() - have[depth] - base_one;
    for (int zero = 0; zero <= have[depth]; zero++) {
      int real_zero = base_zero + zero;
      ll tmp = value;
      for (int i = 0; i < (int)indices[depth].size(); i++) {
        int index = indices[depth][i];
        if (i + 1 <= real_zero) {
          value &= ~(1ULL << index);
        } else {
          value |= (1ULL << index);
        }
      }
      dfs(depth + 1);
      value = tmp;
    }
  };
  dfs(0);
  assert(value == 1);
  cout << "ACCEPTED\n";
  return 0;
}
