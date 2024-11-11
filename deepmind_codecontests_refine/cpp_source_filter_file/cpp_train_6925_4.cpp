#include <bits/stdc++.h>
using namespace std;
int lookup[200020][20];
int n, d, v;
long long res;
pair<int, int> a[200010];
bool f;
int bins(int l, int r, int v) {
  int mid = (l + r) / 2;
  if (a[mid].first <= v && a[mid + 1].first > v) return mid;
  if (a[mid].first > v) return bins(l, mid - 1, v);
  if (a[mid + 1].first <= v) return bins(mid + 1, r, v);
}
int query(int l, int r) {
  int h = sizeof(int) * 8 - __builtin_clz(r - l + 1) - 1;
  if (l == r) return lookup[l][0];
  if (a[lookup[l][h]].second < a[lookup[r - (1 << h) + 1][h]].second)
    return lookup[l][h];
  else
    return lookup[r - (1 << h) + 1][h];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> d >> v >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  a[n++] = make_pair((d), (0));
  a[n++] = make_pair((0), (2147483647));
  a[n++] = make_pair((2147483647), (2147483647));
  sort(a, a + n);
  for (int i = 0; i < n; i++) lookup[i][0] = i;
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      if (a[lookup[j][i - 1]].second <
          a[lookup[j + (1 << i - 1)][i - 1]].second)
        lookup[j][i] = lookup[j][i - 1];
      else
        lookup[j][i] = lookup[j + (1 << i - 1)][i - 1];
    }
  }
  for (int i = 0, now = v; a[i].first < d;) {
    if (now == v) {
      now -= a[i + 1].first - a[i].first;
      if (now < 0) {
        f = true;
        break;
      }
      if (a[++i].first >= d) break;
    }
    int r = bins(0, n - 1, a[i].first + v);
    int best = r;
    vector<int> st;
    while (best >= i) {
      best = query(i, best);
      st.push_back(best--);
    }
    int nxt = st.front();
    if (nxt == i) {
      int buy = v - now;
      res += 1LL * buy * a[i].first;
      now = v;
    }
    while (st.size() >= 2) {
      int buy = a[st[st.size() - 2]].first - a[st[st.size() - 1]].first - now;
      buy = max(0, buy);
      res += 1LL * a[st.back()].second * buy;
      now += buy;
      now -= a[st[st.size() - 2]].first - a[st[st.size() - 1]].first;
      st.pop_back();
    }
    i = st.front();
  }
  cout << (f ? -1 : res) << endl;
  return 0;
}
