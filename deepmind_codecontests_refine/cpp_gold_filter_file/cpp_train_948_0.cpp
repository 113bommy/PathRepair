#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 1;
struct segTree {
  segTree *left = nullptr, *right = nullptr;
  long long val = 0;
};
long long v(segTree* cur) { return (cur == nullptr) ? 0 : cur->val; }
segTree* righ(segTree* cur) { return (cur == nullptr) ? nullptr : cur->right; }
segTree* lef(segTree* cur) { return (cur == nullptr) ? nullptr : cur->left; }
long long m;
void update(long long p, long long val, segTree* cur, long long ll = 1,
            long long rr = m) {
  if (ll == rr) {
    cur->val = val;
    return;
  }
  long long mid = (ll + rr) / 2;
  if (p <= mid) {
    if (cur->left == nullptr) cur->left = new segTree();
    update(p, val, cur->left, ll, mid);
  } else {
    if (cur->right == nullptr) cur->right = new segTree();
    update(p, val, cur->right, mid + 1, rr);
  }
  cur->val = v(cur->left) + v(cur->right);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  srand(time(0));
  long long n;
  cin >> n >> m;
  segTree* s[n];
  for (long long i = 0; i < n; i++) s[i] = new segTree();
  long long sum = 0;
  priority_queue<pair<long long, long long>> mx, mn;
  for (long long i = 0; i < n; i++) {
    long long q;
    cin >> q;
    sum += q;
    mx.push({q, i});
    mn.push({-q, i});
    for (long long j = 0; j < q; j++) {
      long long k;
      cin >> k;
      update(k, 1, s[i]);
    }
  }
  long long lim = sum % n != 0;
  vector<vector<long long>> ans;
  while (mx.top().first + mn.top().first > lim) {
    long long sf = mx.top().first, ss = -mn.top().first;
    long long f = mx.top().second, u = mn.top().second;
    mx.pop();
    mn.pop();
    long long l = 1, r = m;
    segTree *c1 = s[f], *c2 = s[u];
    while (l != r) {
      long long mid = (l + r) / 2;
      if (v(righ(c1)) > v(righ(c2))) {
        c1 = righ(c1);
        c2 = righ(c2);
        l = mid + 1;
      } else {
        c1 = lef(c1);
        c2 = lef(c2);
        r = mid;
      }
    }
    ans.push_back({f, u, l});
    update(l, 0, s[f]);
    update(l, 1, s[u]);
    mx.push({sf - 1, f});
    mn.push({-(sf - 1), f});
    mx.push({ss + 1, u});
    mn.push({-(ss + 1), u});
  }
  cout << ans.size() << endl;
  for (vector<long long> i : ans)
    cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] << endl;
}
