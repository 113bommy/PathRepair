#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 9;
int f[100010];
int get(int x) { return f[x] == x ? x : f[x] = get(f[x]); }
int main() {
  int n, m;
  int a, b;
  int ans = 1;
  int i;
  cin >> n >> m;
  for (i = 1; i <= n; i++) f[i] = i;
  for (i = 1; i <= m; i++) {
    cin >> a >> b;
    if (get(a) == get(b))
      ans = ans * 2 % M;
    else
      f[get(a)] = get(b);
    cout << (ans - 1 + M) % M << endl;
  }
  return 0;
}
