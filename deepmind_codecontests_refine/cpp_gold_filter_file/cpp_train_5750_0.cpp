#include <bits/stdc++.h>
using namespace std;
long long int isfind(long long int parent[], long long int b) {
  if (parent[b] == b) {
    return b;
  }
  parent[b] = isfind(parent, parent[b]);
  return parent[b];
}
void build(long long int tree[], long long int arr[], long long int node,
           long long int start, long long int end) {
  if (start == end) {
    tree[node] = arr[start];
    return;
  }
  long long int mid = (start + end) / 2;
  build(tree, arr, 2 * node, start, mid);
  build(tree, arr, 2 * node + 1, mid + 1, end);
  tree[node] = tree[2 * node] | tree[2 * node + 1];
}
long long int range_in_query(long long int tree[], long long int node,
                             long long int start, long long int end,
                             long long int l, long long int r) {
  if (start > end || start > r || end < l) {
    return 0;
  }
  if (start >= l && end <= r) {
    return tree[node];
  }
  long long int mid = (start + end) / 2;
  long long int range = range_in_query(tree, 2 * node, start, mid, l, r);
  long long int range1 = range_in_query(tree, 2 * node + 1, mid + 1, end, l, r);
  return range | range1;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n + 1];
  vector<long long int> out(n + 1), in(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] > 0) {
      out[i]++;
      in[arr[i]]++;
    }
  }
  vector<long long int> res;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0 && out[i] == 0) {
      res.push_back(i);
    }
  }
  if (res.size() == 1) {
    for (int i = 1; i <= n; i++) {
      if (in[i] == 0 && i != res[0]) {
        arr[res[0]] = i;
        out[res[0]]++;
        in[i]++;
        break;
      }
    }
  } else {
    for (int i = 0; i < res.size(); i++) {
      arr[res[i]] = res[(i + 1) % res.size()];
      out[res[i]]++;
      in[res[(i + 1) % res.size()]]++;
    }
  }
  vector<long long int> f_in, f_out;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) f_in.push_back(i);
    if (out[i] == 0) f_out.push_back(i);
  }
  for (int i = 0; i < f_in.size(); i++) {
    arr[f_out[i]] = f_in[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
