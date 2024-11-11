#include <bits/stdc++.h>
using namespace std;
long long int ar[1000000];
int price[10000];
int price1[10000];
int ans[100000];
char asl[1000][1000];
int fac(int b) {
  if (b == 1 || b == 0) return 1;
  return fac(b - 1) * b;
}
int main() {
  long long n, m, i, j, a, b, c, d, f, l, h, maxx;
  string s, t, o;
  char ch, ch1;
  float p, y, x, u;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a;
    for (j = 0; j < a; j++) {
      cin >> b;
      ar[b] = 1;
    }
  }
  d = 0;
  for (i = 1; i <= m; i++) {
    if (ar[i] == 0) {
      d = 1;
      break;
    }
  }
  if (d == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
