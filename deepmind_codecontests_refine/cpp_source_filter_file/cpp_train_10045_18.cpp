#include <bits/stdc++.h>
using namespace std;
const int MAXN = 60;
int n, k, f[MAXN];
void build() {
  f[1] = f[2] = 1;
  for (int i = 3; i < MAXN; ++i) f[i] = f[i - 1] + f[i - 2];
}
int main() {
  build();
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    if (f[n - i + 1] >= k)
      cout << i << " ";
    else {
      k -= f[n - i + 1];
      cout << i + 1 << " " << i << " ";
      ++i;
    }
  cout << endl;
  return 0;
}
