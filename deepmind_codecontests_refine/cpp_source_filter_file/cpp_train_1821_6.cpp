#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
int offset = (1 << 18);
int bestChannel;
int bestVideo = -1;
map<pair<int, int>, int> toInd;
struct Tree {
  vector<pair<int, int> > p;
  vector<pair<int, int> > t;
  void addVideo(int l, int r) { p.push_back(make_pair(l, r)); }
  void consider(long long len, int ind, long long c, int channel) {
    if (len * c > ans) {
      ans = len * c;
      bestVideo = ind;
      bestChannel = channel;
    }
  }
  void query(int a, int b, long long c, int channel) {
    auto it = lower_bound(p.begin(), p.end(), make_pair(a, -1000000005));
    bool dofirst = 0;
    if (it == p.begin()) {
      dofirst = 1;
    } else {
      dofirst = 0;
      --it;
      long long len = min(b, it->second) - a;
      consider(len, toInd[*it], c, channel);
    }
    int lo = (it - p.begin());
    if (dofirst) lo = -1;
    int hi = p.size();
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (p[mid].second > b) {
        hi = mid;
      } else
        lo = mid;
    }
    int x;
    if (dofirst)
      x = offset;
    else
      x = (it - p.begin()) + 1 + offset;
    int y = hi + offset;
    while (y > x) {
      consider(t[x].first, t[x].second, c, channel);
      if (y % 2) consider(t[y - 1].first, t[y - 1].second, c, channel);
      x = (x + 1) / 2;
      y = y / 2;
    }
  }
  void fix() {
    vector<pair<int, int> > np;
    sort(p.begin(), p.end());
    np.push_back(p[0]);
    for (int i = 1; i < p.size(); ++i) {
      if (p[i].first == np.back().first)
        np[np.size() - 1] = p[i];
      else if (p[i].second > np.back().second)
        np.push_back(p[i]);
    }
    p = np;
    t.resize(offset * 2);
    for (int i = 0; i < p.size(); ++i) {
      t[offset + i] = make_pair(p[i].second - p[i].first, toInd[p[i]]);
    }
    for (int i = offset - 1; i >= 0; --i) {
      t[i] = max(t[2 * i], t[2 * i + 1]);
    }
  }
} tree1, tree2;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (0); i < int(n); ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    tree1.addVideo(l, r);
    tree2.addVideo(-r, -l);
    toInd[make_pair(l, r)] = i;
    toInd[make_pair(-r, -l)] = i;
  }
  tree1.fix();
  tree2.fix();
  for (int i = (0); i < int(m); ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    tree1.query(a, b, c, i);
    tree2.query(a, b, c, i);
  }
  if (bestVideo == -1) {
    puts("0");
  } else {
    printf("%I64d\n%d %d\n", ans, bestVideo + 1, bestChannel + 1);
  }
}
