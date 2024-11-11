#include <bits/stdc++.h>
using namespace std;
void domod(int &a, long long b) { a = (a + b) % 1000000007; }
set<int> st;
template <typename T>
void kmp(T &a) {
  int n = strlen(a), i, j;
  int *pf;
  pf = new int[n + 1];
  pf[0] = pf[1] = 0;
  for (i = 2; i <= n; i++) {
    j = pf[i - 1];
    while (j > 0 && a[i - 1] != a[j]) j = pf[j];
    if (a[i - 1] == a[j]) j++;
    pf[i] = j;
  }
  i = pf[n];
  while (i > 0) {
    st.insert(n - i);
    i = pf[i];
  }
}
int main() {
  int n, m, *a, *q, ix, pl;
  char *p;
  scanf("%d %d", &n, &m);
  p = new char[n + 1];
  a = new int[n + 1];
  q = new int[n + 1];
  for (auto i = 0; i <= n; i++) {
    a[i] = 26;
  }
  scanf("%s", p);
  kmp(p);
  for (auto i = 0; i < m; i++) {
    scanf("%d", q + i);
  }
  sort(q, q + m);
  ix = 1;
  pl = strlen(p);
  for (int i = 1; i < m; i++)
    if (q[i - 1] + pl >= q[i] && st.find(q[i] - q[i - 1]) == st.end()) {
      cout << 0 << endl;
      return 0;
    }
  for (auto i = 0; i < m; i++)
    if (q[i] + pl > ix) {
      for (int j = max(ix, q[i]); j < q[i] + pl; j++) a[j] = 1;
      ix = q[i] + pl;
    }
  pl = 1;
  for (int i = 1; i <= n; i++) {
    pl = (1LL * pl * a[i]) % 1000000007;
  }
  cout << pl << endl;
  return 0;
}
