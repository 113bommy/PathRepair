#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
long long n, m, p;
int a[200003], b[200003];
int main() {
  multiset<int> st;
  scanf("%I64d%I64d%I64d", &n, &m, &p);
  int k = 0;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &a[i]);
  }
  for (int i = (1); i <= (m); i++) {
    scanf("%d", &b[i]);
  }
  int ans[200001], anscnt = 0;
  for (int i = (1); i <= (p); i++) {
    int q = i;
    st.clear();
    multiset<int>::iterator it;
    if (q + (m - 1) * p <= n) {
      for (int j = (1); j <= (m); j++) st.insert(b[j]);
      for (int j = (0); j <= (m - 2); j++) {
        it = st.find(a[j * p + q]);
        if (it != st.end()) {
          st.erase(it);
        } else {
          st.insert(-1 * a[j * p + q]);
        }
      }
    }
    while (q + (m - 1) * p <= n) {
      it = st.find(a[(m - 1) * p + q]);
      if (it != st.end()) {
        st.erase(it);
      } else {
        st.insert(-1 * a[(m - 1) * p + q]);
      }
      if (st.empty()) ans[++anscnt] = q;
      it = st.find(a[q] * -1);
      if (it != st.end()) {
        st.erase(it);
      } else {
        st.insert(a[q]);
      }
      q += p;
    }
  }
  sort(ans + 1, ans + anscnt + 1);
  printf("%d\n", anscnt);
  for (int i = (1); i <= (anscnt); i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
