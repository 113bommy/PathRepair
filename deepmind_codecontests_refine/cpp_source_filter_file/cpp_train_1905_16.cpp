#include <bits/stdc++.h>
using namespace std;
int n, a[1000020], san[1000020], cnt;
int pre[1000020];
set<int> st;
set<int>::iterator p, q;
unsigned long long calc() {
  long long ret = 1ull * n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
  ret += 1ull * 2 * n * (n - 1) * (n - 2) / 6;
  ret += n * (n - 1) / 2;
  return ret;
}
bool lucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return 0;
    x /= 10;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  unsigned long long ans = calc();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (lucky(a[i])) {
      san[++cnt] = i;
    }
  }
  san[++cnt] = n + 1;
  for (int i = 1; i < cnt; ++i) {
    pre[i] = 0;
    for (int j = 1; j < i; ++j) {
      if (a[san[i]] == a[san[j]]) {
        pre[i] = j;
      }
    }
  }
  for (int i = 2; i < cnt; ++i) {
    st.clear();
    st.insert(0);
    unsigned long long tmp = 0;
    for (int j = i; j < cnt; ++j) {
      if (pre[j] < i) {
        for (int k = pre[j]; k; k = pre[k]) {
          p = st.lower_bound(san[k]);
          q = p;
          p--;
          if (q != st.end()) {
            tmp += 1ull * (san[k] - *p) * (*q - san[k]) * (san[i] - san[i - 1]);
          } else {
            tmp += 1ull * (san[k] - *p) * (san[i] - san[i - 1] + 1) *
                   (san[i] - san[i - 1]) / 2;
            tmp += 1ull * (san[k] - *p) * (san[i - 1] - san[k]) *
                   (san[i] - san[i - 1]);
          }
          st.insert(san[k]);
        }
      }
      ans -= tmp * (san[j + 1] - san[j]);
    }
  }
  cout << ans << endl;
  return 0;
}
