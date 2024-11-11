#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10, mod = 1e9 + 7, length = 25;
int add(int a, int b) { return (0LL + a + b + mod) % mod; }
int mul(int a, int b) { return (1LL * a * b) % mod; }
vector<vector<long long>> mul(vector<vector<long long>> A,
                              vector<vector<long long>> B) {
  vector<vector<long long>> C(A.size(), vector<long long>(B[0].size()));
  for (int i = 1; i < A.size(); i++)
    for (int j = 1; j < B[0].size(); j++)
      for (int m = 1; m < A[1].size(); m++)
        C[i][j] = add(C[i][j], mul(A[i][m], B[m][j]));
  return C;
}
vector<vector<long long>> pow(vector<vector<long long>> A, long long p) {
  if (p == 1) return A;
  if (p & 1) return mul(A, pow(A, p - 1));
  vector<vector<long long>> temp = pow(A, p / 2);
  temp = mul(temp, temp);
  return temp;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> first(2, vector<long long>(4, 0)),
      T(4, vector<long long>(4, 0));
  first[1][2] = 1;
  for (int i = 1; i < 4; i++)
    for (int j = 1; j < 4; j++) T[i][j] = (abs(j - i) < 2);
  vector<pair<long long, int>> v;
  for (int i = 0; i < n; i++) {
    long long a, l, r;
    cin >> a >> l >> r;
    v.push_back({l - 1, a});
    v.push_back({r, -a});
  }
  sort(v.begin(), v.end());
  long long lst = 1;
  vector<long long> mwgod(4, 1);
  for (int i = 0; i < 2 * n; i++) {
    long long dist = v[i].first - lst;
    if (dist > 0) first = mul(first, pow(T, dist));
    if (v[i].second < 0)
      mwgod[abs(v[i].second)]++;
    else
      mwgod[abs(v[i].second)]--;
    for (int j = 1; j < 4; j++)
      for (int k = 1; k < 4; k++) T[j][k] = (abs(k - j) < 2 && mwgod[k] > 0);
    lst = v[i].first;
  }
  first = mul(first, pow(T, m - lst));
  cout << first[1][2] << '\n';
}
