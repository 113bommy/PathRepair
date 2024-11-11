#include <bits/stdc++.h>
using namespace std;
long long jilu[100050];
int main(int argc, const char* argv[]) {
  long long n, h, k;
  scanf("%lld%lld%lld", &n, &h, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &jilu[i]);
  }
  jilu[n] = h;
  int num = 0;
  long long have = 0;
  int i;
  for (i = 0;;) {
    while (num < n) {
      if (h - have >= jilu[num]) {
        have += jilu[num];
        num++;
      } else
        break;
    }
    long long tmp = (have - (h - jilu[num]) + k - 1) / k;
    have = max(0ll, have - k * tmp);
    i += tmp;
    if (num == n) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
