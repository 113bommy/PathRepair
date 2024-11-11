#include <bits/stdc++.h>
using namespace std;
long long n, k, s, l;
int main() {
  cin >> n >> k >> s;
  int cur = 1;
  if (k > s || k * (n - 1) < s)
    printf("NO");
  else {
    printf("YES\n");
    while (k > 0) {
      l = min(n - 1, s - k + 1);
      if (cur - l > 0)
        cur -= l;
      else
        cur += l;
      printf("%d ", cur);
      s -= l;
      k--;
    }
  }
  return 0;
}
