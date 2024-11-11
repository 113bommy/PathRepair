#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 14;
int n, a[maxn], lst[maxn], fen[maxn];
void upd(int p, int v) {
  for (p++; p < maxn; p += p & -p) fen[p] += v;
}
void upd(int l, int r, int v) { upd(l, v), upd(r, -v); }
int get(int p) {
  int ans = 0;
  for (p++; p; p ^= p & -p) ans += fen[p];
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  memset(lst, -1, sizeof lst);
  int l = 0;
  deque<int> st;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (l <= lst[a[i]]) {
      upd(l + a[st.front()], l + a[st.front()] + 1, -1);
      if (st.front() == l) st.pop_back();
      l++;
    }
    while (st.size() && a[st.back()] <= a[i]) {
      int j = st.back();
      upd((st.size() == 1 ? l : st[st.size() - 2] + 1) + a[j], j + a[j] + 1,
          -1);
      st.pop_back();
    }
    upd((st.empty() ? l : st.back() + 1) + a[i], i + a[i] + 1, 1);
    st.push_back(i);
    ans += get(i + 1);
    lst[a[i]] = i;
  }
  cout << ans << '\n';
}
