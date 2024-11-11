#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void umax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void umin(T &a, T b) {
  if (a > b) a = b;
}
const int N = 10000;
int n, p;
bool a[N];
bool ispa(int x) {
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (int i = 3; i <= sqrt(x); i += 2)
    if (x % i == 0) return 0;
  return 1;
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int pp = i;
    if (ispa(pp)) {
      a[i] = 1;
      p++;
      for (int j = i * i; j <= n; j *= i) p++, a[j] = 1;
    }
  }
  cout << p << "\n";
  for (int i = 1; i <= n; i++)
    if (a[i] == 1) cout << i << " ";
  return 0;
}
