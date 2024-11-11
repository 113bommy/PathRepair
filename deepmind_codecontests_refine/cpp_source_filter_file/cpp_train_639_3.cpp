#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
long long p[maxn];
int main() {
  long long n, m, k;
  while (cin >> n >> m >> k) {
    for (int i = 0; i < m; ++i) {
      cin >> p[i];
    }
    int step = 0;
    int sub = 0;
    int num = 1;
    for (int i = 1; i < m; ++i) {
      if ((p[i] - 1 - sub) / 5 == (p[i - 1] - 1 - sub) / 5) {
        num++;
        continue;
      } else {
        step += 1;
        sub += num;
        num = 1;
      }
    }
    step += 1;
    cout << step << endl;
  }
  return 0;
}
