#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int iinf = INT_MAX;
const long long linf = LONG_MAX;
const int MOD = 1e9 + 7;
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int n;
int a[110];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - (a + 1);
  if (n <= 1)
    cout << "NO\n";
  else
    cout << a[2] << endl;
}
