#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
long long n, a, d;
int main() {
  cin >> n >> a >> d;
  cout << 368131125ll * a % 1000000000 * 12 * 1000000000 + 1 << ' '
       << 368131125ll * d % 1000000000 * 12 * 1000000000;
  return 0;
}
