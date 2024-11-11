#include <bits/stdc++.h>
using namespace std;
int a[400010];
int mp[400010];
int nxt[400010];
int flag[400010];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    mp[a[i]]++;
  }
  memset(flag, -1, sizeof(flag));
  for (int i = n - 1; i >= 0; i--) {
    if (flag[a[i]] == -1)
      nxt[i] = n;
    else
      nxt[i] = flag[a[i]];
    flag[a[i]] = i;
  }
  set<int> library;
  set<pair<int, int> > st;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    mp[a[i]]--;
    if (library.find(a[i]) == library.end()) {
      ret++;
      if (library.size() == k) {
        library.erase(st.begin()->second);
        st.erase(st.begin());
      }
    } else {
      st.erase(make_pair(-i, a[i]));
    }
    st.insert(make_pair(-nxt[i], a[i]));
    library.insert(a[i]);
  }
  printf("%d\n", ret);
  return 0;
}
