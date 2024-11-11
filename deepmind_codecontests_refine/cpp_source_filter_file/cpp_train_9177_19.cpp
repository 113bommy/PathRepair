#include <bits/stdc++.h>
template <class T>
T read(std::istream& is) {
  T x;
  return is >> x, x;
}
template <class T>
T read() {
  T x;
  return std::cin >> x, x;
}
const int oo = 0x7fffffff;
const long long OO = 0x7fffffffffffffff;
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x >= 0) x = -x - 1;
    A[i] = x;
  }
  if (n & 1) {
    int id = 0;
    for (int i = 1; i < n; ++i)
      if (abs(A[i]) < abs(A[id])) id = i;
    A[id] = 0 - A[id] - 1;
  }
  for (auto x : A) cout << x << ' ';
  cout << '\n';
  return 0;
}
