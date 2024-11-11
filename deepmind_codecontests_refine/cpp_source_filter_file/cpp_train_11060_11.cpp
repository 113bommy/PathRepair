#include <bits/stdc++.h>
using namespace std;
const int max_n = 200111, inf = 1000111222;
int m[max_n];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = n / 2;
    if (cnt % 2 == 1) {
      puts("NO");
      continue;
    }
    int cur = 3;
    for (int i = 0; i < cnt; ++i) {
      m[i] = cur;
      if (i % 2) {
        m[cnt + i] = cur + 1;
      } else {
        m[cnt + i] = cur - 1;
      }
      cur += 5;
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
      cout << m[i] << ' ';
    }
    cout << "\n";
  }
  return 0;
}
