#include <bits/stdc++.h>
using namespace std;
int n, k, x;
long long a[200010];
set<pair<long long, int> > st;
int main() {
  int op = 1, pos;
  long long val;
  scanf("%d%d%d", &n, &k, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    if (a[i] < 0) op = -op;
    st.insert(make_pair(abs(a[i]), i));
  }
  while (k--) {
    pos = st.begin()->second;
    val = st.begin()->first;
    if (a[pos] < 0) op = -op;
    if (op == -1)
      a[pos] += x;
    else
      a[pos] -= x;
    st.erase(st.begin());
    st.insert(make_pair(abs(a[pos]), pos));
    if (a[pos] < 0) op = -op;
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", a[i]);
  printf("\n");
  return 0;
}
