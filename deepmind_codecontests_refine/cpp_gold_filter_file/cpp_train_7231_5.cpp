#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000;
struct el {
  int l, r, id;
} a[MAX_N], b[MAX_N];
long k[MAX_N];
class compare {
 public:
  bool operator()(el a, el b) { return a.r < b.r; }
};
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].l >> a[i].r;
    a[i].id = i;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i].l >> b[i].r >> k[i];
    b[i].id = i;
  }
  compare cmp;
  sort(a, a + n, cmp);
  sort(b, b + m, cmp);
  int uk = 0;
  vector<int> ans(n);
  multimap<int, int> mp;
  for (int i = 0; i < m; i++) {
    while (uk < n && a[uk].r <= b[i].r)
      mp.insert(make_pair(a[uk].l, a[uk].id)), uk++;
    map<int, int>::iterator it;
    for (it = mp.lower_bound(b[i].l); it != mp.end() && k[b[i].id];
         it = mp.lower_bound(b[i].l)) {
      ans[it->second] = b[i].id + 1;
      k[b[i].id]--;
      mp.erase(it);
    }
  }
  if (mp.empty() && uk == n) {
    cout << "YES\n";
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
  } else
    cout << "NO";
  return 0;
}
