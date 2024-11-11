#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool uin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  if (k >= n * (n - 1) / 2) {
    cout << "no solution";
  } else {
    for (int i = 0; i < (int)(n); ++i) {
      cout << i << " " << i * (n + 1) * 10 << endl;
    }
  }
  return 0;
}
