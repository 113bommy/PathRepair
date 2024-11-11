#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 1 << 28;
int in() {
  int x;
  scanf("%d", &x);
  return x;
}
long long In() {
  long long x;
  cin >> x;
  return x;
}
double inreal() {
  double x;
  scanf("%lf", &x);
  return x;
}
string instr() {
  char buf[1001];
  scanf("%s", buf);
  return (string)buf;
}
int main() {
  int i, j, k, n = in();
  int pos = 1, skip = 1;
  for ((i) = (0); (i) < (int)(n - 1); (i)++) {
    if (i) putchar(' ');
    cout << (pos + 1) % n;
    pos = pos + skip + 1;
    skip++;
  }
  puts("");
  return 0;
}
