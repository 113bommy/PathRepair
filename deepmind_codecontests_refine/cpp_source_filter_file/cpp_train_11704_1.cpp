#include <bits/stdc++.h>
using namespace std;
int p[1000006], n, l[1000006], r[1000006];
bool fin[1000006];
void fans(int *l) {
  int i;
  vector<pair<int, int> > v;
  set<pair<int, int> > s;
  set<pair<int, int> >::iterator it;
  v.push_back(pair<int, int>(1, -1));
  s.insert(pair<int, int>(1, -1));
  for ((i) = 0; (i) < (n); (i)++) {
    if (fin[p[i]]) {
      while (v.size() && v.back().first > p[i]) {
        s.erase(v.back());
        v.pop_back();
      }
      v.push_back(pair<int, int>(-p[i], i));
      s.insert(pair<int, int>(-p[i], i));
    } else {
      it = s.upper_bound(pair<int, int>(-p[i], -1));
      if (v.size() && it != s.end()) {
        {}
        l[i] = (i - it->second) - 1;
      }
    }
  }
}
int bit[1000006];
void add(int val, int idx) {
  while (idx <= n) {
    bit[idx] += val;
    idx += ((idx) & (-idx));
  }
}
int sum(int idx) {
  int sm = 0;
  while (idx) {
    sm += bit[idx];
    idx -= ((idx) & (-idx));
  }
  return sm;
}
int main() {
  int i, j, k, val;
  scanf("%d%d", &n, &k);
  for ((i) = 0; (i) < (n); (i)++) scanf("%d", &p[i]);
  for ((i) = 0; (i) < (k); (i)++) {
    scanf("%d", &val);
    fin[val] = true;
  }
  fans(l);
  reverse(p, p + n);
  fans(r);
  long long ans = n - k;
  for ((i) = 0; (i) < (n); (i)++) {
    ans += l[i] + r[i];
  }
  vector<pair<int, int> > v;
  for ((i) = 0; (i) < (n); (i)++) {
    if (!fin[p[i]]) v.push_back(pair<int, int>(p[i], n - i));
  }
  sort(v.begin(), v.end());
  int lf, rg, pos;
  for ((i) = 0; (i) < (v.size()); (i)++) {
    pos = v[i].second - 1;
    lf = pos - l[pos];
    rg = pos + r[n - pos - 1] + 1;
    ans -= sum(rg) - sum(lf);
    add(1, pos + 1);
  }
  cout << ans << endl;
  return 0;
}
