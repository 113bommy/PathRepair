#include <bits/stdc++.h>
using namespace std;
int res[100005], sz;
bool prime[100005], used[100005];
int main() {
  int n;
  cin >> n;
  for (int p = 2; p <= n / 2; ++p) {
    if (prime[p]) continue;
    for (int j = p; j <= n; j += p) prime[j] = 1;
    if (p == 2) continue;
    int len = 0, pos = 0;
    for (int j = p; j <= n; j += p) {
      if (used[j]) continue;
      used[j] = 1;
      if (j % 2 == 0) pos = sz;
      res[sz++] = j;
      len++;
    }
    if (len & 1) {
      swap(res[pos], res[sz - 1]);
      used[res[sz - 1]] = 0;
      sz--;
    }
  }
  for (int i = 2; i <= n; i += 2)
    if (!used[i]) res[sz++] = i;
  cout << sz / 2 << endl;
  for (int i = 0; i + 1 < sz; i += 2) printf("%d %d\n", res[i], res[i + 1]);
  return 0;
}
