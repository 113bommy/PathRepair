#include <bits/stdc++.h>
using namespace std;
const int modn = 1e9 + 7;
int mod(int x) { return x < 0 ? x + modn : x < modn ? x : x - modn; }
const int N = 200005;
int a[N];
map<int, int> m;
int main() {
  int n;
  long long s = 0, ans = 0;
  int q = -1;
  m[0] = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    s += a[i];
    if (m.count(s)) q = max(q, m[s]);
    m[s] = i;
    ans += i - q - 1;
  }
  cout << ans << endl;
  return 0;
}
