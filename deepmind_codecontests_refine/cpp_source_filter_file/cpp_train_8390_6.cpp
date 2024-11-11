#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double PI = 3.14159265359;
vector<vector<long long>> operator*(const vector<vector<long long>>& mat1,
                                    const vector<vector<long long>>& mat2) {
  int n1 = mat1.size(), m1 = mat1[0].size(), n2 = mat2.size(),
      m2 = mat2[0].size();
  vector<vector<long long>> ans(n1, vector<long long>(m2, 0));
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < m2; j++) {
      for (int k = 0; k < m1; k++) {
        ans[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  return ans;
}
vector<vector<long long>> matPow(const vector<vector<long long>>& mat,
                                 long long p) {
  auto ans = mat, prod = mat;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans.size(); j++) {
      ans[i][j] = i == j;
    }
  }
  while (p) {
    if (p & 1) {
      ans = ans * prod;
    }
    prod = prod * prod;
    p = p >> 1;
  }
  return ans;
}
void disp(vector<vector<long long>> mat) {
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[0].size(); j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> vi;
  bool fnz = false;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x >= k) {
      cout << 0;
      return 0;
    }
    if (x || fnz) vi.push_back(x), fnz = true;
  }
  n = vi.size();
  if (n < 6) {
    vector<vector<long long>> mat(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        mat[i][j] = 1;
      }
    }
    vector<vector<long long>> vim(1);
    vim[0] = vi;
    long long r = 1;
    auto prod = vim * matPow(mat, r);
    auto prodb = mat;
    while (prod[0][n - 1] < k) {
      r *= 2;
      prodb = prodb * prodb;
      prod = vim * prodb;
    }
    long long l = 1ll;
    while (l < r) {
      long long mid = (l + r) / 2;
      prod = vim * matPow(mat, mid);
      if (prod[0][n - 1] < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    cout << l << endl;
    return 0;
  }
  int ct = 1;
  while (1) {
    vector<long long> temp(n, 0);
    temp[0] = vi[0];
    for (int i = 1; i < n; i++) {
      temp[i] = temp[i - 1] + vi[i];
      if (temp[i] >= k) {
        cout << ct;
        return 0;
      }
    }
    vi = temp;
    ct++;
  }
  return 0;
}
