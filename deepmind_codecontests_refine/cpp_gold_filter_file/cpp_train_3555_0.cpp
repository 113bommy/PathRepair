#include <bits/stdc++.h>
using namespace std;
struct e {
  int x, idx;
  bool operator<(const e &i) const { return x < i.x; }
};
const int N = 3e5L + 11;
int s[N], t[N];
e stone[N];
struct e2 {
  int i, j, d;
};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", s + i);
    stone[i] = {s[i], i};
  }
  for (int i = 0; i < n; i++) scanf("%d", t + i);
  sort(stone, stone + n);
  sort(t, t + n);
  vector<e> st;
  vector<e2> ans;
  bool f = 1;
  for (int i = 0; i < n; i++) {
    int d = t[i] - stone[i].x;
    if (d > 0) {
      st.push_back({d, stone[i].idx});
    } else {
      d = -d;
      while (st.size() && d) {
        int use = min(st.back().x, d);
        st.back().x -= use;
        d -= use;
        ans.push_back({st.back().idx, stone[i].idx, use});
        if (st.back().x == 0) st.pop_back();
      }
      if (d) f = 0;
    }
  }
  if (f && !st.size()) {
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (e2 i : ans) printf("%d %d %d\n", i.i + 1, i.j + 1, i.d);
  } else
    cout << "NO\n";
}
