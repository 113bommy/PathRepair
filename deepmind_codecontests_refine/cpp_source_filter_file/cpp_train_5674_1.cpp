#include <bits/stdc++.h>
using namespace std;
long long scan() {
  register char r;
  bool start = false, neg = false;
  long long ret = 0;
  while (true) {
    r = getchar();
    if ((r - '0' < 0 || r - '0' > 9) && r != '-' && !start) {
      continue;
    }
    if ((r - '0' < 0 || r - '0' > 9) && r != '-' && start) {
      break;
    }
    if (start) ret = (ret << 3) + (ret << 1);
    start = true;
    if (r == '-')
      neg = true;
    else
      ret += r - '0';
  }
  if (!neg)
    return ret;
  else
    return -ret;
}
const int inf = 1 << 30;
const long double eps = 1e-9;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long a[200];
long long b[200];
int main(void) {
  long long n, m;
  cin >> n >> m;
  long long mx = 0;
  for (int i = 0; i < (int)m; i++) {
    mx = 0;
    for (int j = 0; j < (int)n; j++) {
      cin >> a[j];
      if (a[j] > a[mx]) mx = j;
    }
    b[mx]++;
  }
  mx = 0;
  for (int i = 0; i < (int)m; i++) {
    if (b[i] > b[mx]) mx = i;
  }
  cout << mx + 1 << '\n';
}
