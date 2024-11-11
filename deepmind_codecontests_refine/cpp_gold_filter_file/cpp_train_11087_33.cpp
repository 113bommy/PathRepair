#include <bits/stdc++.h>
using namespace std;
int A[100005];
int Tree[400005];
void build(int node, int left, int right) {
  if (right < left) return;
  if (left == right) {
    Tree[node] = A[left];
    return;
  }
  build(2 * node, left, (left + right) / 2);
  build(2 * node + 1, (left + right) / 2 + 1, right);
  Tree[node] = max(Tree[2 * node], Tree[2 * node + 1]);
}
int query(int node, int left, int right, int L, int R) {
  if (left > right || left > R || right < L) return INT_MIN;
  if (left >= L && right <= R) return Tree[node];
  int l = query(2 * node, left, (left + right) / 2, L, R);
  int r = query(2 * node + 1, (left + right) / 2 + 1, right, L, R);
  return max(l, r);
}
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  build(1, 0, N - 1);
  for (int i = 0; i < N - 1; i++)
    cout << max(0, query(1, 0, N - 1, i + 1, N - 1) - A[i] + 1) << " ";
  cout << "0";
}
