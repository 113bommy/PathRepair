#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long n, k;
vector<long long> a;
bool Read() {
  cin >> n;
  if (cin.eof()) return 0;
  cin >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return 1;
}
namespace Matrix {
template <typename T>
vector<vector<T>> Zero(int _n, int _m) {
  return vector<vector<T>>(_n, vector<T>(_m, 0));
}
template <typename T>
vector<vector<T>> Identity(int _n) {
  vector<vector<T>> ans = Zero<T>(_n, _n);
  for (int i = 0; i < _n; i++) ans[i][i] = 1;
  return ans;
}
template <typename T>
vector<vector<T>> Multiplication(const vector<vector<T>>& _a,
                                 const vector<vector<T>>& _b) {
  assert(_a[0].size() == _b.size());
  vector<vector<T>> ans = Zero<T>(_a.size(), _b[0].size());
  for (int i = 0; i < _a.size(); i++)
    for (int j = 0; j < _b[0].size(); j++)
      for (int k = 0; k < _a[0].size(); k++)
        ans[i][j] = (ans[i][j] + _a[i][k] * _b[k][j] % M) % M;
  return ans;
}
template <typename T>
vector<vector<T>> Power(vector<vector<T>> _a, long long expo) {
  vector<vector<T>> ans = Identity<T>(_a.size());
  while (expo > 0) {
    if (expo & 1) ans = Multiplication(ans, _a);
    expo >>= 1;
    _a = Multiplication(_a, _a);
  }
  return ans;
}
}  // namespace Matrix
void Process() {
  vector<vector<long long>> exor(n, vector<long long>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      exor[i][j] = __builtin_popcountll(a[i] ^ a[j]) % 3 == 0;
  const vector<vector<long long>> p = Matrix::Power(exor, k - 1);
  long long ans = 0;
  for (const auto& row : p)
    for (long long x : row) ans = (ans + x) % M;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (Read()) Process();
  return 0;
}
