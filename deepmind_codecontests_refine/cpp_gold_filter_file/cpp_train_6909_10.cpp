#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int *tree;
void buildTree(int node, int arr[], int start, int end) {
  if (start == end) {
    tree[node] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  buildTree(2 * node + 1, arr, start, mid);
  buildTree(2 * node + 2, arr, mid + 1, end);
  tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}
int query(int node, int start, int end, int L, int R) {
  if (L <= start && R >= end)
    return tree[node];
  else if (L > end || R < start)
    return INT32_MAX;
  else {
    int mid = (start + end) / 2;
    int c1 = query(2 * node + 1, start, mid, L, R);
    int c2 = query(2 * node + 2, mid + 1, end, L, R);
    return min(c1, c2);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, x;
  cin >> n >> x;
  x--;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  tree = new int[4 * n];
  buildTree(0, a, 0, n - 1);
  int i = n - 1;
  bool ans = false;
  while (i >= 0) {
    long long y = a[i];
    if (x > i) {
      long long p = y * n + x - i;
      int h1 = query(0, 0, n - 1, i + 1, x);
      int h2 = -1;
      if (x + 1 < n) h2 = query(0, 0, n - 1, x + 1, n - 1);
      int h3 = query(0, 0, n - 1, 0, i - 1);
      bool cond = true;
      if (h1 < y + 1) cond = false;
      if (h2 != -1 && h2 < y) cond = false;
      if (h3 < y) cond = false;
      if (cond) {
        long long b[n];
        b[i] = p;
        for (int j = i + 1; j < x + 1; j++) {
          b[j] = a[j] - (y + 1);
        }
        for (int j = x + 1; j < n; j++) {
          b[j] = a[j] - y;
        }
        for (int j = 0; j < i; j++) {
          b[j] = a[j] - y;
        }
        for (auto e : b) {
          cout << e << " ";
        }
        cout << endl;
        break;
      }
    } else if (x < i) {
      long long p = y * n + n - i - 1 + x + 1;
      int h1 = query(0, 0, n - 1, i + 1, n - 1);
      int h3 = query(0, 0, n - 1, 0, x);
      int h2 = query(0, 0, n - 1, x + 1, i - 1);
      bool cond = true;
      if (h1 < y + 1) cond = false;
      if (h2 < y) cond = false;
      if (h3 < y + 1) cond = false;
      if (cond) {
        long long b[n];
        b[i] = p;
        for (int j = i + 1; j < n; j++) {
          b[j] = a[j] - (y + 1);
        }
        for (int j = 0; j < x + 1; j++) {
          b[j] = a[j] - (y + 1);
        }
        for (int j = x + 1; j < i; j++) {
          b[j] = a[j] - y;
        }
        for (auto e : b) {
          cout << e << " ";
        }
        cout << endl;
        break;
      }
    } else {
      long long p = y * n;
      int h1 = -1;
      if (i + 1 < n) {
        h1 = query(0, 0, n - 1, i + 1, n - 1);
      }
      int h3 = -1;
      if (x - 1 >= 0) {
        h3 = query(0, 0, n - 1, 0, x - 1);
      }
      bool cond = true;
      if (h1 != -1 && h1 < y) cond = false;
      if (h3 != -1 && h3 < y) cond = false;
      if (cond) {
        long long b[n];
        b[i] = p;
        for (int j = i + 1; j < n; j++) {
          b[j] = a[j] - (y);
        }
        for (int j = 0; j < x; j++) {
          b[j] = a[j] - (y);
        }
        for (auto e : b) {
          cout << e << " ";
        }
        cout << endl;
        break;
      }
    }
    i--;
  }
}
