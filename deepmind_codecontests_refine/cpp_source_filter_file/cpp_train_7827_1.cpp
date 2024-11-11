#include <bits/stdc++.h>
using namespace std;
long long int mod_expo(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
void build(long long int tree[], long long int ar[], long long int node,
           long long int start, long long int end) {
  if (start == end) {
    tree[node] = ar[start];
  }
  long long int mid = (start + end) / 2;
  build(tree, ar, 2 * node, start, mid);
  build(tree, ar, 2 * node + 1, mid + 1, end);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(long long int tree[], long long int ar[], long long int node,
            long long int indx, long long int start, long long int end,
            long long int val) {
  if (start == end) {
    tree[node] = val;
    ar[indx] = val;
  }
  long long int mid = (start + end) / 2;
  if (indx >= start && indx <= mid) {
    update(tree, ar, 2 * node, indx, start, mid, val);
  } else {
    update(tree, ar, 2 * node + 1, indx, mid + 1, end, val);
  }
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long int query(long long int tree[], long long int ar[],
                    long long int node, long long int l, long long int r,
                    long long int start, long long int end) {
  if (l > end || r > start) return 0;
  if (start >= l && end <= r) return tree[node];
  long long int mid = (start + end) / 2;
  long long int p1 = query(tree, ar, 2 * node, l, r, start, mid);
  long long int p2 = query(tree, ar, 2 * node + 1, l, r, mid + 1, end);
  return (p1 + p2);
}
int main() {
  long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ar[n + 4];
    long long int k;
    long long int m[n + 9];
    set<long long int> s;
    for (long long int i = 1; i <= n; i++) {
      cin >> k;
      ar[i] = k;
      m[k] = i;
    }
    long long int count = n - 1;
    for (long long int i = 1; i <= n && count; i++) {
      k = m[i];
      while (ar[k] > ar[k - 1] && count && k > i && s.find(k - 1) == s.end()) {
        long long int temp = ar[k];
        ar[k] = ar[k - 1];
        ar[k - 1] = temp;
        s.insert(k - 1);
        m[ar[k]]++;
        m[ar[k - 1]]--;
        count--;
        k--;
      }
    }
    for (long long int i = 1; i <= n; i++) cout << ar[i] << " ";
    cout << endl;
  }
  return 0;
}
