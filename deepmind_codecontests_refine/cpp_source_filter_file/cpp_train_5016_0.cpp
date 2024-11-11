#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 15;
int n, k, a[N], b[N], res[N], qid;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0, ggd = n; i < ggd; i++) cin >> a[i];
  for (int i = 0, ggd = n; i < ggd; i++) cin >> b[i];
  set<int> l, r, cur;
  for (int i = 0, ggd = n; i < ggd; i++) {
    cur.insert(a[i]);
    cur.insert(b[i]);
    if (a[i] != b[i]) {
      if (l.count(a[i]))
        l.erase(a[i]);
      else
        r.insert(a[i]);
      if (r.count(b[i]))
        r.erase(b[i]);
      else
        l.insert(b[i]);
    }
    if (!(((int)(l).size()))) {
      assert(!(((int)(r).size())));
      for (auto it : cur) res[it] = qid;
      cur.clear();
      qid++;
    }
  }
  if (((int)(cur).size())) {
    for (auto it : cur) res[it] = qid;
    qid++;
  }
  if (qid >= k) {
    cout << "YES\n";
    for (int i = 1, ggd = n + 1; i < ggd; i++)
      cout << (char)('a' + min(26, res[i]));
    cout << "\n";
  } else
    cout << "NO\n";
}
