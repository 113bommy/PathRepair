#include <bits/stdc++.h>
template <typename T>
using MaxHeap = std::priority_queue<T>;
template <typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
std::vector<T> vec(int len, T elem) {
  return std::vector<T>(len, elem);
}
template <typename T>
void vdeb(std::vector<T> &da) {
  for (int i = 0; i < da.size(); i++) {
    if (i == da.size() - 1)
      std::cout << da[i];
    else
      std::cout << da[i] << ' ';
  }
  std::cout << std::endl;
}
template <typename T>
void vdeb(std::vector<std::vector<T>> &da) {
  for (int i = 0; i < da.size(); i++) vdeb(da[i]);
  std::cout << std::endl;
}
using namespace std;
int power(int x, long long y, int m) {
  if (y == 0) return 1;
  if (y & 1)
    return power(x, y - 1, m) * x % m;
  else {
    int tmp = power(x, y / 2, m);
    return tmp * tmp % m;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> da(n);
  for (int i = (0); i < (int)(n); i++) cin >> da[i];
  if (n > m) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 1;
  for (int i = (1); i < (int)(n); i++) {
    for (int j = (0); j < (int)(i); j++) {
      ans *= abs(da[i] - da[j]);
      ans %= m;
    }
  }
  cout << ans << endl;
}
