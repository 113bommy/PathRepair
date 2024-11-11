#include <bits/stdc++.h>
using namespace std;
string toString(int h) {
  stringstream ss;
  ss << h;
  return ss.str();
}
long long A[102], tree[4 * 102];
long long B[102], tree1[4 * 102];
void build_tree(int node, int a, int b) {
  if (a == b)
    tree[node] = a;
  else {
    build_tree(2 * node + 1, a, (a + b) / 2);
    build_tree(2 * node + 2, (a + b) / 2 + 1, b);
    if (A[tree[2 * node + 1]] <= A[tree[2 * node + 2]])
      tree[node] = tree[2 * node + 1];
    else
      tree[node] = tree[2 * node + 2];
  }
}
int query(int x, int y, int node, int a, int b) {
  if (x > b || y < a) return -1;
  if (a >= x && b <= y) return tree[node];
  int p1 = query(x, y, 2 * node + 1, a, (a + b) / 2);
  int p2 = query(x, y, 2 * node + 2, (a + b) / 2 + 1, b);
  if (p1 == -1) return tree[node] = p2;
  if (p2 == -1) return tree[node] = p1;
  if (A[p1] <= A[p2]) return tree[node] = p1;
  return tree[node] = p2;
}
void build_tree1(int node, int a, int b) {
  if (a == b)
    tree1[node] = a;
  else {
    build_tree1(2 * node + 1, a, (a + b) / 2);
    build_tree1(2 * node + 2, (a + b) / 2 + 1, b);
    if (B[tree1[2 * node + 1]] >= B[tree1[2 * node + 2]])
      tree1[node] = tree1[2 * node + 1];
    else
      tree1[node] = tree1[2 * node + 2];
  }
}
int query1(int x, int y, int node, int a, int b) {
  if (x > b || y < a) return -1;
  if (a >= x && b <= y) return tree1[node];
  int p1 = query1(x, y, 2 * node + 1, a, (a + b) / 2);
  int p2 = query1(x, y, 2 * node + 2, (a + b) / 2 + 1, b);
  if (p1 == -1) return tree1[node] = p2;
  if (p2 == -1) return tree1[node] = p1;
  if (B[p1] >= B[p2]) return tree1[node] = p1;
  return tree1[node] = p2;
}
int main() {
  int n, k;
  cin >> n >> k;
  set<int> pe;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    pe.insert(a);
    A[i] = a;
    B[i] = a;
  }
  build_tree(0, 0, n - 1);
  build_tree1(0, 0, n - 1);
  vector<string> ad;
  long long mini = 9999999;
  for (int i = 0; i < k; i++) {
    int mi = query(0, n - 1, 0, 0, n - 1);
    int ma = query1(0, n - 1, 0, 0, n - 1);
    if (mi != ma) {
      mini = min(mini, abs(B[ma] - A[mi]));
      A[ma]--;
      A[mi]++;
      B[ma]--;
      B[mi]++;
      build_tree(0, 0, n - 1);
      build_tree1(0, 0, n - 1);
      ad.push_back(toString(ma + 1) + " " + toString(mi + 1));
    }
  }
  int mi = query(0, n - 1, 0, 0, n - 1);
  int ma = query1(0, n - 1, 0, 0, n - 1);
  mini = min(mini, abs(B[ma] - A[mi]));
  if (pe.size() == 1) {
    cout << 0 << " " << 0 << endl;
  } else {
    cout << mini << " " << k << endl;
    for (int i = 0; i < ad.size(); i++) {
      cout << ad[i] << endl;
    }
  }
}
