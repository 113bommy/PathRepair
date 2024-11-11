#include <bits/stdc++.h>
using namespace std;
struct Query {
  int price, size, id;
  Query() : price(0), size(0), id(0) {}
  Query(int price, int size, int id) : price(price), size(size), id(id) {}
  bool operator<(Query other) const {
    if (size != other.size) return size < other.size;
    return price > other.price;
  }
};
int n;
vector<Query> shoe;
int m;
vector<Query> customer;
bool vis[100005][5];
long long dp[100005][5];
pair<int, int> track[100005][5];
int binser(vector<Query> &vec, int target) {
  int lo = 1, hi = vec.size() - 2, mid;
  while (lo < hi) {
    mid = (lo + hi) >> 1;
    if (vec[mid].size < target)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}
long long solve(int id, int taken) {
  if (id > m) return 0;
  if (vis[id][taken]) return dp[id][taken];
  int next_taken = taken >> min(2, customer[id + 1].size - customer[id].size);
  long long res = solve(id + 1, next_taken);
  pair<int, int> next = {-1, next_taken};
  if (taken < 1) {
    int target = binser(shoe, customer[id].size);
    if (target <= n && shoe[target].size == customer[id].size &&
        shoe[target].price <= customer[id].price) {
      next_taken =
          (taken | 1) >> min(2, customer[id + 1].size - customer[id].size);
      long long cur = shoe[target].price + solve(id + 1, next_taken);
      if (cur > res) {
        res = cur;
        next = {target, next_taken};
      }
    }
  }
  if (taken < 2) {
    int target = binser(shoe, customer[id].size + 1);
    if (target <= n && shoe[target].size == customer[id].size + 1 &&
        shoe[target].price <= customer[id].price) {
      next_taken =
          (taken | 2) >> min(2, customer[id + 1].size - customer[id].size);
      long long cur = shoe[target].price + solve(id + 1, next_taken);
      if (cur > res) {
        res = cur;
        next = {target, next_taken};
      }
    }
  }
  vis[id][taken] = 1;
  track[id][taken] = next;
  return dp[id][taken] = res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  shoe.assign(n + 2, Query());
  for (int i = 1; i <= n; i++) {
    int price, size;
    cin >> price >> size;
    shoe[i] = Query(price, size, i);
  }
  cin >> m;
  customer.assign(m + 2, Query());
  for (int i = 1; i <= m; i++) {
    int price, size;
    cin >> price >> size;
    customer[i] = Query(price, size, i);
  }
  customer[m + 1].size = 2e9;
  sort(shoe.begin() + 1, shoe.begin() + n + 1);
  sort(customer.begin() + 1, customer.begin() + m + 1);
  long long ans = solve(1, 0);
  vector<pair<int, int>> ans_list;
  for (int i = 1, j = 0; i <= m; i++) {
    int l = track[i][j].first;
    int k = track[i][j].second;
    if (l != -1) {
      ans_list.push_back({customer[i].id, shoe[l].id});
    }
    j = k;
  }
  cout << ans << "\n";
  cout << ans_list.size() << "\n";
  for (auto it : ans_list) {
    cout << it.first << " " << it.second << "\n";
  }
  return 0;
}
