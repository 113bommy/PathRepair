#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  while (scanf("%d%d", &k, &n) != EOF) {
    unsigned int a[100001];
    int b, c, d, e;
    int i = 0;
    for (i = 0; i < k; i++) {
      scanf("%d.%d.%d.%d", &b, &c, &d, &e);
      a[i] = (b << 24) + (c << 16) + (d << 8) + e;
    }
    set<unsigned int> st;
    unsigned int sum = 0;
    for (i = 31; i >= 1; i--) {
      sum |= (1 << i);
      st.clear();
      for (int j = 0; j < k; j++) {
        st.insert(sum & a[j]);
      }
      if (st.size() == n) break;
    }
    if (st.size() == n) {
      printf("%d.%d.%d.%d\n", sum >> 24, (sum << 8) >> 24, (sum << 16) >> 24,
             (sum << 24) >> 24);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
