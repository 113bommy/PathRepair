#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double PI = acos(-1);
const double EPS = 1e-8;
const int N = 10000002;
int num[N];
int main() {
  for (int i = 1; i * i < N; ++i) {
    for (int j = 1; i * i * j < N; ++j) {
      if (i == 1)
        num[j] = j;
      else
        num[i * i * j] = min(num[i * i * j], j);
    }
  }
  int a, n;
  cin >> a >> n;
  long long ans = 0;
  for (int i = a; i < a + n; ++i) ans += num[i];
  cout << ans << endl;
}
