#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, a, b, k, f;
  cin >> n >> a >> b >> k >> f;
  unordered_map<string, int> mp;
  int cur_indx = 0;
  map<pair<int, int>, int> tot_cost;
  string cur_st = "";
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string st;
    cin >> st;
    if (mp.find(st) == mp.end()) {
      mp[st] = cur_indx++;
    }
    int in1 = mp[st];
    int cur_cost;
    if (st == cur_st) {
      cur_cost = b;
    } else
      cur_cost = a;
    string des;
    cin >> des;
    if (mp.find(des) == mp.end()) {
      mp[des] = cur_indx++;
    }
    int in2 = mp[des];
    if (in1 > in2) swap(in1, in2);
    tot_cost[{in1, in2}] += cur_cost;
    cur_st = des;
    ans += cur_cost;
  }
  priority_queue<int> q;
  for (auto st : tot_cost) {
    q.push(st.second);
  }
  while (k && !q.empty()) {
    int cur_cost = q.top();
    q.pop();
    if (cur_cost > f) {
      ans -= cur_cost;
      ans += f;
    } else {
      break;
    }
    k--;
  }
  cout << ans;
}
