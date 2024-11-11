#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 123, inf = 1e9, mod = 1e9 + 7;
int n, b[maxn];
long long a[maxn], c[maxn];
set<int> st;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    st.insert(b[i]);
  }
  if (st.size() == 1) {
    if (b[0] == 0) {
      puts("YES");
      for (int i = 0; i < n; i++) printf("666 ");
    } else
      puts("NO");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (b[i] < b[(i + 1) % n]) {
      for (int j = 0; j < n; j++) c[(j + n - i - 2 + n + n) % n] = b[j];
      a[n - 1] = c[n - 1];
      for (int j = n - 2; j >= 0; j--) {
        long long mn = c[(j - 1 + 1) % n] + 1;
        a[j] = c[j] + (mn / a[j + 1] + 1) * a[j + 1];
      }
      puts("YES");
      for (int j = 0; j < n; j++)
        printf("%lld ", a[(j + n - i - 2 + n + n) % n]);
      return 0;
    }
  }
  puts("NO");
  return 0;
}
