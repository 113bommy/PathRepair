#include <bits/stdc++.h>
using namespace std;
const int N = 0;
int n, k, x, t;
string s;
vector<int> v;
int arr[100005];
int segTree[400005];
int build(int start, int end, int node, int op) {
  if (start == end) {
    segTree[node] = arr[start];
    return segTree[node];
  }
  int mid = (start + end) / 2;
  int left = build(start, mid, 2 * node, op ^ 1);
  int right = build(mid + 1, end, 2 * node + 1, op ^ 1);
  segTree[node] = op == 1 ? left | right : left ^ right;
  return segTree[node];
}
int update(int start, int end, int node, int ind, int value, int op) {
  if (start == end) {
    segTree[node] = arr[ind];
    return segTree[node];
  }
  int mid = (start + end) / 2;
  int left = segTree[node * 2];
  if (start <= ind && mid >= ind) {
    left = update(start, mid, node * 2, ind, value, op ^ 1);
  }
  int right = segTree[node * 2 + 1];
  if (end >= ind && mid + 1 <= ind) {
    right = update(mid + 1, end, node * 2 + 1, ind, value, op ^ 1);
  }
  segTree[node] = op == 1 ? left | right : left ^ right;
  return segTree[node];
}
int main() {
  scanf("%d%d", &n, &k);
  int height = n;
  n = pow(2, n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
  }
  build(1, n, 1, height % 2 != 0);
  for (int i = 0, ind, val; i < k; i++) {
    scanf("%d%d", &ind, &val);
    arr[ind] = val;
    update(1, n, 1, ind, val, height % 2 != 0);
    printf("%d\n", segTree[1]);
  }
  return 0;
}
