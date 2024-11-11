#include <bits/stdc++.h>
using namespace std;
map<long long, int> st;
int main() {
  long long n, i, j, k, l;
  scanf("%lld", &n);
  if (n <= 11) {
    st.clear();
    long long ans;
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= n - i; j++) {
        for (k = 0; k <= n - j - i; k++) {
          l = n - j - i - k;
          if (l < 0) {
            break;
          }
          ans = 50 * i + 10 * j + 5 * k + l;
          st[ans]++;
        }
      }
    }
    printf("%d", st.size());
  } else {
    printf("%lld", 292 + (n - 11) * (long long)(49));
  }
}
