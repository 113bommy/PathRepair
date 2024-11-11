#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
const double eps = (1e-10);
int m, type, x, l, c, n, rem;
vector<pair<long long, pair<int, int>>> v;
vector<int> a;
bool flag;
long long idx, query;
stringstream ans;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin >> m;
  rem = m;
  for (int i = 0; i < (int)(m); ++i) {
    --rem;
    cin >> type;
    if (type == 1) {
      cin >> x;
      a.push_back(x);
    } else {
      cin >> l >> c;
      for (int j = 0; j < (int)(c); ++j) {
        for (int k = 0; k < (int)(l); ++k) a.push_back(a[k]);
        if (((int)((a).size())) > 100000) {
          if (j < c - 1)
            v.push_back(make_pair(((int)((a).size())), make_pair(l, 2))),
                idx = (c - j - 1) * idx;
          flag = true;
          break;
        }
      }
    }
    if (flag) break;
  }
  idx += ((int)((a).size()));
  for (int i = 0; i < (int)(rem); ++i) {
    cin >> type;
    if (type == 1) {
      cin >> x;
      v.push_back(make_pair(idx++, make_pair(x, 1)));
    } else {
      cin >> l >> c;
      v.push_back(make_pair(idx, make_pair(l, 2)));
      idx += l * c;
    }
  }
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> query;
    --query;
    if (query < ((int)((a).size())))
      ans << a[query] << ' ';
    else {
      auto it = lower_bound(((v).begin()), ((v).end()),
                            make_pair(query, make_pair(0, 0)));
      if (it == v.end() || it->first > query) --it;
      if (it->second.second == 2)
        ans << a[(query - (it->first)) % (it->second.first)] << ' ';
      else
        ans << it->second.first << ' ';
    }
  }
  cout << ans.str();
  return 0;
}
