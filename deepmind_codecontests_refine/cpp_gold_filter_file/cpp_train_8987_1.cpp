#include <bits/stdc++.h>
using namespace std;
int n;
int fa[100009];
long long Edge[100009];
int find(int x, long long &val) {
  if (fa[x] == x) return x;
  int f = find(fa[x], val);
  val = (val + Edge[x]) % 1000000007;
  fa[x] = f;
  Edge[x] = val;
  return f;
}
int main() {
  int a, b, k;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      fa[i] = i;
      Edge[i] = 0;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &k);
      for (int j = 0; j < k; j++) {
        scanf("%d%d", &a, &b);
        long long val = 0;
        a = find(a, val);
        fa[a] = i;
        Edge[a] = (val + b) % 1000000007;
        ans = (ans + Edge[a]) % 1000000007;
      }
    }
    cout << (ans + 1000000007) % 1000000007 << endl;
  }
  return 0;
}
