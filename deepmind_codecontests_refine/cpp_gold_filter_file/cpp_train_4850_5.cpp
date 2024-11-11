#include <bits/stdc++.h>
template <typename T>
void pMin(T& a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void pMax(T& a, T b) {
  if (b > a) {
    a = b;
  }
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c);
template <typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& c) {
  std::cout << "(" << c.first << ", " << c.second << ")";
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c) {
  if (c.size() == 0) {
    os << "{}";
    return os;
  }
  os << "{" << c[0];
  for (int i = 1; i < (int)c.size(); i++) {
    os << ", " << c[i];
  }
  os << "}";
  return os;
}
const int inf = 2e9;
using namespace std;
int n, k;
vector<bool> canDo;
bool check(int x) {
  if (x == 3) {
    cout << "";
  }
  int prevGood = 0, prevTaken = 0;
  int remK = k - 1;
  for (int i = 1; i < n; i++) {
    if (canDo[i]) prevGood = i;
    if (i - prevTaken - 1 >= x) {
      if (prevGood == prevTaken || remK == 0 || (i != n - 1 && remK == 1)) {
        return false;
      }
      prevTaken = prevGood;
      remK--;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  canDo.resize(n);
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    canDo[i] = (ch == '0');
  }
  int ans = inf;
  int l = -1, r = inf;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << "\n";
  return 0;
}
