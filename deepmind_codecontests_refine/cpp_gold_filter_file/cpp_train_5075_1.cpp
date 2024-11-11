#include <bits/stdc++.h>
using namespace std;
const long long NN = 111111;
const long long ML = 2147483647;
const long long MLL = 9223372036854775807;
const long double pi = acos(-1);
long long n, dx, dy, m, i, k, j, x, y, B, C, T, f, l, r, z, q, e, d, w, c, ii,
    res, a[NN], b[NN], A[NN], s, M;
vector<long long> v;
template <typename T>
void stop(T s) {
  cout << s << "\n";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    a[i] = a[i - 1];
    b[i] = b[i - 1];
    cin >> x;
    A[i] = x;
    if (x & 1)
      b[i]++;
    else
      a[i]++;
  }
  for (i = 1; i < n; i++)
    if (a[i] == b[i]) v.push_back(abs(A[i + 1] - A[i]));
  sort(v.begin(), v.end());
  for (i = 0; i < v.size(); i++) {
    if (v[i] > m) break;
    m -= v[i];
    res++;
  }
  cout << res << "\n";
  return 0;
}
