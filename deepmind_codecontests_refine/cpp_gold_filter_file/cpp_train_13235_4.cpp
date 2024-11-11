#include <bits/stdc++.h>
const int mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using namespace std;
template <class myType>
void p(vector<myType>& v) {
  for (myType i : v) cout << i << " ";
  cout << endl;
}
template <class myType>
void pv(vector<vector<myType>>& vv) {
  for (auto& v : vv) p(v);
}
template <class myType>
void GetInputV(vector<myType>& v, int n) {
  v.resize(n);
  for (myType& i : v) cin >> i;
}
template <class myType>
void GetInputVV(vector<vector<myType>>& vv, int m, int n) {
  vv.resize(m);
  for (vector<myType>& v : vv) GetInputV(v, n);
}
void same(vector<vector<int>>& A, vector<vector<int>>& B) {
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A[0].size(); j++) {
      if (A[i][j] != B[i][j]) {
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
}
void flip(vector<vector<int>>& A, int i, int j) {
  A[i][j] = !A[i][j];
  A[i + 1][j] = !A[i + 1][j];
  A[i][j + 1] = !A[i][j + 1];
  A[i + 1][j + 1] = !A[i + 1][j + 1];
}
int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> A, B;
  GetInputVV(A, m, n);
  GetInputVV(B, m, n);
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (A[i][j] != B[i][j]) {
        flip(A, i, j);
      }
    }
  }
  same(A, B);
  return 0;
}
