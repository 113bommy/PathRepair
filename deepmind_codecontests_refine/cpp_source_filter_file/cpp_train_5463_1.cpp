#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VL = vector<long long>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using MII = map<int, int>;
using MIVI = map<int, VI>;
using MLL = map<LL, LL>;
int READ_INT() {
  int temp;
  cin >> temp;
  return temp;
}
LL READ_LONG() {
  LL temp;
  cin >> temp;
  return temp;
}
string READ_STRING() {
  string temp;
  cin >> temp;
  return temp;
}
const int MOD = int(1e9) + 7;
const int INF = 1e9 + 5;
const double PI = acos(-1.0);
const double EPS = 1e-9;
int n, m, k;
VVI healths;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  healths.assign(n, VI(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> healths[i][j];
    }
  }
  VI k_array(m, 0), ans_arr;
  deque<VI> q;
  int ans = 0;
  vector<map<int, int>> index_wise_counter(m);
  vector<set<int>> index_wise_values(m);
  for (int i = 0; i < n; ++i) {
    VI health = healths[i];
    q.push_back(health);
    for (int j = 0; j < m; ++j) {
      k_array[j] = max(k_array[j], health[j]);
      index_wise_counter[j][health[j]] += 1;
      index_wise_values[j].insert(health[j]);
    }
    while (accumulate(k_array.begin(), k_array.end(), 0) > k) {
      VI rem = q.front();
      q.pop_front();
      for (int j = 0; j < m; ++j) {
        index_wise_counter[j][rem[j]] -= 1;
        if (index_wise_counter[j][rem[j]] == 0) {
          index_wise_values[j].erase(rem[j]);
        }
        if (index_wise_values[j].size())
          k_array[j] = *index_wise_values[j].rbegin();
        else
          k_array[j] = 0;
      }
    }
    if (q.size() > ans) {
      ans = q.size();
      ans_arr = k_array;
    }
  }
  {
    for (auto x___ : ans_arr) cout << x___ << " ";
    cout << "\n";
  };
  return 0;
}
