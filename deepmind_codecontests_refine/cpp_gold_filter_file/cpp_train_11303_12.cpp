#include <bits/stdc++.h>
using namespace std;
const int inf = ~0u >> 2;
const long long INF = (1LL << 62) - 1;
double eps = 1e-9;
const int N = 106 + 5;
const int M = 21;
long long a[N][N];
char str[N];
int main() {
  long long n;
  cin >> n;
  scanf("%s", str);
  int len = strlen(str);
  reverse(str, str + len);
  long long x = 1;
  int i = 0;
  long long y = 0;
  long long s = 0;
  int k = 0;
  long long v = 1;
  int t = 1;
  while (i + k < len) {
    if (y + max(1, (str[i + k] - '0')) * v < n) {
      y += (str[i + k] - '0') * v;
      v *= 10;
      if (str[i + k] != '0') t = i + k + 1;
      k++;
    } else {
      v = 1;
      s += y * x;
      x *= n;
      i = t;
      t = i + 1;
      k = 0;
      y = 0;
    }
  }
  s += y * x;
  cout << s << endl;
  return 0;
}
