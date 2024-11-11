#include <bits/stdc++.h>
using namespace std;
int const sg[33] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6,  2, 1, 8, 7,  5,
                    9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 14};
set<int> s;
int main() {
  int n;
  while (cin >> n) {
    int t = 0;
    s.clear();
    for (int i = 2; i * i <= n; ++i) {
      if (s.find(i) != s.end()) continue;
      int cnt = 0;
      int mx = n / i;
      for (int j = i; j <= n; j *= i) {
        s.insert(j);
        ++cnt;
        if (j > mx) break;
      }
      t ^= sg[cnt];
    }
    int c1 = n - s.size();
    t ^= (c1 & 1);
    if (t == 0)
      puts("Petya");
    else
      puts("Vasya");
  }
  return 0;
}
