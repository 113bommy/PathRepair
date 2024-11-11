#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int main() {
  long long int t = 1;
  while (t--) {
    long long int n, i, j, m;
    cin >> n >> m;
    long long int x, k, y;
    cin >> x >> k >> y;
    long long int arr[n];
    long long int brr[m];
    unordered_map<long long int, long long int> mp;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
      mp[arr[i]] = i;
    }
    for (i = 0; i < m; i++) cin >> brr[i];
    long long int ans = 1;
    long long int minind = -1;
    vector<long long int> indxs;
    for (i = 0; i < m; i++) {
      auto it = mp.find(brr[i]);
      if (it == mp.end()) {
        ans = -1;
      } else {
        if (it->second < minind) {
          ans = -1;
        } else {
          indxs.push_back(it->second);
          minind = it->second;
        }
      }
    }
    if (ans == -1) {
      cout << ans << '\n';
      continue;
    }
    if (ans == 1 && m == n) {
      cout << 0 << '\n';
      continue;
    }
    long long int start = 0;
    long long int end = indxs[0];
    long long int gap = end - start;
    long long int max_win = INT_MIN;
    long long int cost = 0;
    for (i = 0; i < indxs.size(); i++) {
      max_win = INT_MIN;
      end = indxs[i];
      if (i == 0) {
        start = 0;
      }
      for (j = start; j < end; j++) {
        max_win = max(arr[j], max_win);
      }
      int flag = 1;
      if (i == 0) {
        if (max_win > arr[end]) {
          flag = 0;
        }
      } else {
        if (max_win > arr[start - 1] && max_win > arr[end]) {
          flag = 0;
        }
      }
      gap = end - start;
      if (gap == 0) {
        start = end + 1;
        continue;
      }
      if (k == 1) {
        if (flag == 0) {
          long long int bcost = (gap - 1) * y;
          long long int fcost = (gap - 1) * x;
          cost += min(fcost, bcost);
          cost += x;
        } else {
          long long int bcost = (gap)*y;
          long long int fcost = (gap)*x;
          cost += min(fcost, bcost);
        }
        start = end + 1;
        continue;
      }
      if (gap < k && flag == 0) {
        ans = -1;
        break;
      }
      long long int rem = gap % k;
      cost += (rem * y);
      gap -= rem;
      if (flag == 1) {
        long long int bcost = gap * y;
        long long int fcost = (gap / k) * x;
        cost += min(fcost, bcost);
      } else {
        long long int segs = gap / k;
        if (segs > 1) {
          long long int config1_cost = x + ((segs - 1) * 2) * y;
          long long int config2_cost = segs * x;
          cost += min(config1_cost, config2_cost);
        } else {
          long long int fcost = (gap / k) * x;
          cost += fcost;
        }
      }
      start = end + 1;
    }
    if (ans == -1) {
      cout << -1 << '\n';
    } else {
      start = indxs[indxs.size() - 1] + 1;
      end = n - 1;
      max_win = INT_MIN;
      for (i = start; i <= end; i++) {
        max_win = max(max_win, arr[i]);
      }
      int flag = 1;
      gap = end - start + 1;
      if (max_win > arr[start - 1]) {
        flag = 0;
      }
      if (k == 1) {
        if (flag == 0) {
          long long int bcost = (gap - 1) * y;
          long long int fcost = (gap - 1) * x;
          cost += min(fcost, bcost);
          cost += x;
        } else {
          long long int bcost = (gap)*y;
          long long int fcost = (gap)*x;
          cost += min(fcost, bcost);
        }
        cout << cost << '\n';
        continue;
      }
      if (gap < k && flag == 0) {
        ans = -1;
        cout << -1 << '\n';
        continue;
      }
      long long int rem = gap % k;
      cost += (rem * y);
      gap -= rem;
      if (flag == 1) {
        long long int bcost = gap * y;
        long long int fcost = (gap / k) * x;
        cost += min(fcost, bcost);
      } else {
        long long int segs = gap / k;
        if (segs > 1) {
          long long int config1_cost = x + ((segs - 1) * 2) * y;
          long long int config2_cost = segs * x;
          cost += min(config1_cost, config2_cost);
        } else {
          long long int fcost = (gap / k) * x;
          cost += fcost;
        }
      }
      cout << cost << '\n';
    }
  }
  return 0;
}
