#include <bits/stdc++.h>
struct heapCmp {
  bool operator()(int i, int j) { return i > j; }
};
template <typename T>
bool cmp(T x, T y) {
  return x > y;
}
using namespace std;
const int MAX = 1e5 + 5;
int main() {
  long long int n, a, b;
  cin >> n >> a >> b;
  long long int tmp = a;
  long long int x = 1, y;
  bool flag = 0;
  while (tmp <= n) {
    long long int zz = n - tmp;
    if (zz % b == 0) {
      flag = 1;
      y = zz / b;
      break;
    } else {
      tmp += a;
      x += 1;
    }
  }
  if (!flag) {
    tmp = b;
    y = 1;
    while (tmp <= n) {
      long long int zz = n - tmp;
      if (zz % a == 0) {
        flag = 1;
        x = zz / b;
        break;
      } else {
        tmp += b;
        y += 1;
      }
    }
  }
  if (flag) {
    cout << "YES\n" << x << " " << y << "\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
