#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
multiset<int> st;
int main() {
  int n, k, temp, te;
  while (~scanf("%d%d", &n, &k)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    scanf("%d", &te);
    for (int i = 1; i < n; i++) {
      scanf("%d", &temp);
      st.insert(temp);
    }
    temp = te + a[k];
    set<int>::iterator it;
    while (!st.empty() && k > 1) {
      te = temp - a[k - 1];
      it = st.lower_bound(te);
      if (it == st.end()) it--;
      if (it != st.begin() && *it > te) it--;
      if (it == st.begin() && *it > te) break;
      k--;
      st.erase(it);
    }
    printf("%d\n", k);
  }
  return 0;
}
