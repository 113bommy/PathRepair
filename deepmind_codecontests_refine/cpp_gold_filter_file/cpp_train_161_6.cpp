#include <bits/stdc++.h>
using namespace std;
template <typename T>
T sqr(T x) {
  return x * x;
}
inline unsigned long long bit(int num) { return 1ull << num; }
int mas[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
int main() {
  long long a;
  cin >> a;
  long long s = 0;
  if (a == 0) s = 1;
  while (a) {
    s += mas[a % 16];
    a /= 16;
  }
  cout << s << endl;
  return 0;
}
