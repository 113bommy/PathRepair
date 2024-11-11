#include <bits/stdc++.h>
using namespace std;
long long int N = 200006;
pair<long long int, long long int> tree[4 * 200006];
vector<long long int> v, v1, v2;
map<long long int, long long int> mp;
long long int temp[200006];
struct node {
  long long int first, second, third;
};
struct node arr[200006];
void update(long long int start, long long int end, long long int node,
            long long int idx, long long int value) {
  if (start == end) {
    tree[node].first += value;
    tree[node].second = (tree[node].first * temp[start]);
    return;
  }
  long long int mid = (start + end) >> 1;
  if (start <= idx && idx <= mid) {
    update(start, mid, 2 * node, idx, value);
  } else {
    update(mid + 1, end, (2 * node) + 1, idx, value);
  }
  tree[node].first = tree[2 * node].first + tree[2 * node + 1].first;
  tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
}
long long int query(long long int start, long long int end, long long int node,
                    long long int k) {
  if (k == 0) return 0;
  if (start != end) {
    long long int mid = (start + end) / 2;
    if (tree[2 * node].first >= k) {
      return query(start, mid, 2 * node, k);
    } else {
      return tree[2 * node].second +
             query(mid + 1, end, 2 * node + 1, k - tree[2 * node].first);
    }
  }
  return temp[start] * k;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].first;
    mp[arr[i].first]++;
  }
  long long int y;
  cin >> y;
  for (int i = 1; i <= y; i++) {
    int a;
    cin >> a;
    arr[a].second = 1;
  }
  cin >> y;
  for (int i = 1; i <= y; i++) {
    int a;
    cin >> a;
    arr[a].third = 1;
  }
  long long int cnt = 1;
  for (auto &i : mp) i.second = cnt++;
  for (auto i : mp) temp[i.second] = i.first;
  for (int i = 1; i <= n; i++) {
    long long int val, a, b;
    val = arr[i].first;
    a = arr[i].second;
    b = arr[i].third;
    if (a == 0 && b == 0)
      update(1, N, 1, mp[val], 1);
    else if (a == 1 && b == 1)
      v.push_back(val);
    else if (a == 0 && b == 1) {
      v1.push_back(val);
    } else
      v2.push_back(val);
  }
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  for (auto i : v) {
    update(1, N, 1, mp[i], 1);
  }
  for (int i = k; i < v1.size(); i++) {
    update(1, N, 1, mp[v1[i]], 1);
  }
  for (int i = k; i < v2.size(); i++) {
    update(1, N, 1, mp[v2[i]], 1);
  }
  while ((int)v1.size() > k) v1.pop_back();
  while ((int)v2.size() > k) v2.pop_back();
  long long int ans = LLONG_MAX;
  long long int sum1 = 0;
  long long int sum2 = 0;
  for (auto i : v1) sum1 += i;
  for (auto i : v2) sum2 += i;
  int node = -1;
  if (v1.size() == k && v2.size() == k && 2 * k <= m) {
    long long int left = m - 2 * k;
    long long int val = sum1 + sum2;
    if (left > 0) {
      long long int pp = query(1, N, 1, left);
      val += pp;
    }
    if (ans > val) {
      ans = val;
      node = 0;
    }
  }
  long long int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    long long int sz = k - i - 1;
    if (sz < 0) break;
    update(1, N, 1, mp[v[i]], -1);
    sum += v[i];
    while ((int)v1.size() > sz) {
      sum1 -= v1.back();
      update(1, N, 1, v1.back(), 1);
      v1.pop_back();
    }
    while ((int)v2.size() > sz) {
      sum2 -= v2.back();
      update(1, N, 1, v2.back(), 1);
      v2.pop_back();
    }
    if (v1.size() == sz && v2.size() == sz) {
      long long int val = sum1 + sum2 + sum;
      long long int left = m - ((2 * sz) + i + 1);
      if (left < 0) continue;
      if (left > 0) {
        long long int pp = query(1, N, 1, left);
        val += pp;
      }
      if (ans > val) {
        ans = val;
        node = i + 1;
      }
    }
  }
  if (ans == LLONG_MAX) ans = -1;
  cout << ans << '\n';
  if (ans == -1) return 0;
}
