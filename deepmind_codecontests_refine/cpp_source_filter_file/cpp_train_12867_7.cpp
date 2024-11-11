#include <bits/stdc++.h>
using namespace std;
struct vouc {
  int l, r, p;
};
vector<vouc> v, vl;
int n, x;
map<int, int> mmap;
long long int res = 1e10;
void read_input() {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    vouc v1;
    cin >> v1.l >> v1.r >> v1.p;
    v.push_back(v1);
    vl.push_back(v1);
  }
  sort(v.begin(), v.end(), [](const vouc &v1, const vouc &v2) {
    if (v1.r != v2.r) return v1.r < v2.r;
    return v1.l < v2.l;
  });
  sort(vl.begin(), vl.end(), [](const vouc &v1, const vouc &v2) {
    if (v1.l != v2.l) return v1.l < v2.l;
    return v1.r < v2.r;
  });
  int p1 = 0;
  for (int i = 0; i < v.size(); ++i) {
    while (vl[i].l > v[p1].r) {
      auto it = mmap.find(v[p1].r - v[p1].l + 1);
      if (it == mmap.end() || it->second > v[p1].p)
        mmap[v[p1].r - v[p1].l + 1] = v[p1].p;
      ++p1;
    }
    auto it = mmap.find(x - (vl[i].r - vl[i].l + 1));
    if (it != mmap.end()) {
      res = min(res, (long long)it->second + v[i].p);
    }
  }
  if (res < 1e10)
    cout << res << endl;
  else
    cout << -1 << endl;
}
int main() {
  read_input();
  return 0;
}
