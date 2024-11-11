#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFFLL;
const unsigned long long UINF = 0xFFFFFFFFFFFFFFFFLL;
const int dCol[] = {0, +1, 0, -1, +1, +1, -1, -1};
const int dRow[] = {-1, 0, +1, 0, -1, +1, +1, -1};
template <typename T>
inline void VIN(vector<T> &i) {
  T x;
  cin >> x;
  i.push_back(x);
}
long long N, M;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  if (N > 27)
    cout << M << "\n";
  else {
    long long dua = pow(2, N);
    cout << M % dua << "\n";
  }
  return 0;
}
