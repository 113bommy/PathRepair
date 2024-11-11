#include <bits/stdc++.h>
using namespace std;
int cost;
int len;
vector<int> out;
int gcd(int a, int b) {
  if (!b) return a;
  len += a / b;
  cost += a / b - 1;
  return gcd(b, a % b);
}
void print(int a, int b, int f = 0) {
  if (a == 0 || b == 0) return;
  if (a > b) {
    a -= b;
    print(a, b, f);
    out.push_back(f);
  } else {
    b -= a;
    print(b, a, !f);
    out.push_back(!f);
  }
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != -1) {
    out.clear();
    int ans = -1;
    int an;
    for (int i = 1; i < m; i++) {
      cost = 0;
      len = 0;
      if (gcd(i, m) != 1 || len != n) continue;
      if (cost < ans || ans == -1) {
        ans = cost;
        an = i;
      }
    }
    if (ans == -1) {
      printf("IMPOSSIBLE\n");
    } else {
      printf("%d\n", ans);
      print(m, an);
      for (int i = 0; i < out.size(); i++) {
        printf("%c", out[i] ^ out[0] ? 'B' : 'T');
      }
      puts("");
    }
  }
  return 0;
}
