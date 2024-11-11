#include <bits/stdc++.h>
using namespace std;
const int N = 154;
long long n, m;
int c[N], a[N], b[N];
void tobinary(long long x, int &len, int a[]) {
  while (x) {
    a[++len] = x % 2;
    x /= 2;
  }
}
int main() {
  cin >> n >> m;
  if (n < m) {
    printf("0");
    return 0;
  }
  int len1 = 0, len2 = 0, len3 = 0;
  tobinary(n, len1, a);
  tobinary(m, len2, b);
  tobinary(n - m, len3, c);
  long long num = 1;
  int has = 0;
  for (int i = 1; i <= len3; i++)
    if (c[i] == 1) has = 1;
  for (int i = 1; i <= len2; i++) {
    if (b[i] == 1) num *= 2;
  }
  if (!has) num /= 2;
  int flag = 1;
  for (int i = 1; i <= len3; i++)
    if (c[i] == 1) {
      if (i == 1) flag = 0;
      if (b[i - 1] != 0) flag = 0;
    }
  if (flag)
    cout << num;
  else
    cout << '0';
}
