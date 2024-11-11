#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v;
  long long w;
};
long long MOD = 1000000007;
long long _MOD = 1000000009;
double EPS = 1e-10;
int f(int e, int o, int t) {
  if (t == 0) return o % 2;
  if (e > t && o > t) return -1;
  if (o <= t) return 0;
  if (e <= t) return (e + o - t * 2) % 2;
}
int main() {
  int n, k;
  cin >> n >> k;
  int e = 0, o = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a % 2 == 0)
      e++;
    else
      o++;
  }
  bool stannis = false;
  if ((n - k) % 2 == 0) {
    if (f(e, o, (n - k) / 2) == 1) stannis = true;
  } else {
    if (e && f(e - 1, o, (n - k) / 2) != 0) stannis = true;
    if (o && f(e, o - 1, (n - k) / 2) != 0) stannis = true;
  }
  cout << (stannis ? "Stannis" : "Daenerys") << endl;
}
