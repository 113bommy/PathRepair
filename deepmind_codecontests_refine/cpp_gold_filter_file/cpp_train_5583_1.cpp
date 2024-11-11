#include <bits/stdc++.h>
using namespace std;
int n, k;
struct sxd {
  int a[11];
  friend bool operator<(sxd a, sxd b) {
    for (int i = 1; i <= k; ++i)
      if (a.a[i] > b.a[i]) return false;
    return true;
  }
};
struct in_set {
  sxd minn, maxx;
  int siz;
  friend bool operator<(in_set a, in_set b) { return a.maxx < b.minn; }
  friend bool operator==(in_set a, in_set b) { return !(a < b || b < a); }
  inline void bing(in_set a) {
    this->siz += a.siz;
    for (int i = 1; i <= k; ++i) {
      minn.a[i] = min(minn.a[i], a.minn.a[i]);
      maxx.a[i] = max(maxx.a[i], a.maxx.a[i]);
    }
  }
};
int main() {
  set<in_set> st;
  st.clear();
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    in_set now;
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &now.minn.a[j]);
      now.maxx.a[j] = now.minn.a[j];
    }
    now.siz = 1;
    for (set<in_set>::iterator it = st.lower_bound(now); it != st.end();) {
      if (now == (*it)) {
        now.bing(*it);
        st.erase(it++);
      } else
        break;
    }
    st.insert(now);
    printf("%d ", st.rbegin()->siz);
  }
  return 0;
}
