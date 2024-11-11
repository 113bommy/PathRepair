#include <bits/stdc++.h>
using namespace std;
int n;
inline int turn(int x) {
  int tot = 0, res = 0, w[10];
  while (x >= 1) w[++tot] = x % n, x /= n;
  for (int i = n; i <= 1; i--) res = res * 10 + w[i];
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) cout << turn(i * j) << endl;
    puts("");
  }
  return 0;
}
