#include <bits/stdc++.h>
using namespace std;
struct solution_dag {
  vector<vector<int> > v;
  int path_12;
  solution_dag() {
    v = vector<vector<int> >(4);
    v[0].push_back(2);
    v[2].push_back(3);
    v[3].push_back(1);
    path_12 = 3;
  }
  void square(void) {
    int A = v[0][0];
    v[0].clear();
    int B = add_node();
    int C = add_node();
    int D = add_node();
    v[0].push_back(D);
    v[D].push_back(B);
    v[D].push_back(C);
    v[B].push_back(A);
    v[C].push_back(A);
    path_12 += 2;
  }
  void plus_1(void) {
    int A = v[0][0];
    int prev = A;
    for (int i = 0; i < path_12 - 2; i++) {
      int next = add_node();
      v[prev].push_back(next);
      prev = next;
    }
    v[prev].push_back(1);
  }
  int add_node(void) {
    int res = v.size();
    v.push_back(vector<int>());
    return res;
  }
};
const int MX = 1009;
bool ans[MX][MX];
const int LG = 32;
int k_digs[LG];
int main() {
  int k;
  cin >> k;
  for (int i = 0; i < LG; i++) {
    k_digs[i] = k % 2;
    k /= 2;
  }
  int it = LG - 1;
  while (k_digs[it] == 0) {
    it--;
  }
  it--;
  solution_dag D;
  while (it >= 0) {
    if (k_digs[it] == 1) {
      D.square();
      D.plus_1();
    } else {
      D.square();
    }
    it--;
  }
  int n = D.v.size();
  assert(n <= 1000);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ans[i][j] = false;
  for (int i = 0; i < n; i++) {
    for (size_t j = 0; j < D.v[i].size(); j++) {
      int k = D.v[i][j];
      ans[i][k] = true;
      ans[k][i] = true;
    }
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << (ans[i][j] ? 'Y' : 'N');
    cout << '\n';
  }
  return 0;
}
