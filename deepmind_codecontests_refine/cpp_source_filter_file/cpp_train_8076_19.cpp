#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int main() {
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i <= n; i++)
    if (i & 1) {
      int l = 0, r = 1e7;
      while (r - l > 1) {
        int s = (l + r) / 2;
        if (max((long long)(3 * i + 2) * (3 * i + 2) +
                    (long long)12 * s * (s - 1) + 3,
                (long long)(3 * i + 1) * (3 * i + 1) + (long long)12 * s * s) <=
            (long long)4 * n * n)
          l = s;
        else
          r = s;
      }
      ans += 2 * l * (1 + int(i > 0));
    } else {
      int l = -1, r = 1e7;
      while (r - l > 1) {
        int s = (l + r) / 2;
        if (max((long long)(3 * i + 2) * (3 * i + 2) + (long long)3 * s * s,
                (long long)12 * s * (s + 1) + 3 +
                    (long long)(3 * i + 1) * (3 * i + 1)) <=
            (long long)4 * n * n)
          l = s;
        else
          r = s;
      }
      if (l >= 0) ans += (2 * l + 1) * (1 + int(i > 0));
    }
  cout << ans << endl;
  return 0;
}
