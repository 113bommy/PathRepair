#include <bits/stdc++.h>
using namespace std;
class ITree {
 private:
  vector<int> T;
  int p;

 public:
  ITree(int n) {
    p = 1;
    while (p < n) p *= 2;
    T.resize(2 * p - 1, 0);
  }
  void Insert(int l, int v) {
    l += p - 1;
    T[l] += v;
    while (l > 0) {
      l = ((l - 1) / 2);
      T[l] += v;
    }
    return;
  }
  int Query(int l, int r) {
    l += p - 1;
    r += p - 1;
    int ans = T[l];
    if (l < r) ans += T[r];
    while (((l - 1) / 2) != ((r - 1) / 2)) {
      if (l % 2 == 1) ans += T[l + 1];
      if (r % 2 == 0) ans += T[r - 1];
      l = ((l - 1) / 2);
      r = ((r - 1) / 2);
    }
    return ans;
  }
};
struct seg {
  long long int x, y, l;
  seg(long long int _x, long long int _y, long long int _l)
      : x(_x), y(_y), l(_l) {}
};
struct event {
  bool beg, is_ins;
  long long int x, y1, y2;
  event(bool _beg, bool _ins, long long int _x, long long int _y1,
        long long int _y2)
      : beg(_beg), is_ins(_ins), x(_x), y1(_y1), y2(_y2) {}
  bool operator<(const event &X) const {
    if (x != X.x)
      return (x < X.x);
    else if (is_ins != X.is_ins) {
      if (is_ins && beg)
        return 1;
      else if (is_ins && !beg)
        return 0;
      else if (X.is_ins && X.beg)
        return 0;
      else if (X.is_ins && !X.beg)
        return 1;
    } else if (is_ins && X.is_ins && beg && !X.beg)
      return 1;
    else
      return 0;
  }
};
bool check(long long int t, vector<seg> &V, vector<seg> &H) {
  vector<event> T;
  vector<int> allY;
  for (int i = (0); i <= ((int)(V).size() - 1); ++i)
    if (V[i].l > 2 * t) {
      allY.push_back(V[i].y + t);
      allY.push_back(V[i].y + V[i].l - t);
      T.push_back(event(0, 0, V[i].x, V[i].y + t, V[i].y + V[i].l - t));
    }
  for (int i = (0); i <= ((int)(H).size() - 1); ++i)
    if (H[i].l > 2 * t) {
      allY.push_back(H[i].y);
      T.push_back(event(1, 1, H[i].x + t, H[i].y, H[i].y));
      T.push_back(event(0, 1, H[i].x + H[i].l - t, H[i].y, H[i].y));
    }
  if (T.empty()) return 0;
  sort(T.begin(), T.end());
  sort(allY.begin(), allY.end());
  allY.resize(unique(allY.begin(), allY.end()) - allY.begin());
  ITree Tree((int)(allY).size());
  for (int i = (0); i <= ((int)(T).size() - 1); ++i) {
    if (T[i].is_ins) {
      int val = ((T[i].beg) ? 1 : -1);
      Tree.Insert(lower_bound(allY.begin(), allY.end(), T[i].y1) - allY.begin(),
                  val);
    } else {
      int y1 = lower_bound(allY.begin(), allY.end(), T[i].y1) - allY.begin(),
          y2 = lower_bound(allY.begin(), allY.end(), T[i].y2) - allY.begin();
      if (Tree.Query(y1, y2) > 0) return 1;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<seg> V, H;
  for (int i = (1); i <= (n); ++i) {
    long long int x, y, l;
    cin >> x >> y >> l;
    V.push_back(seg(x, y, l));
  }
  for (int i = (1); i <= (m); ++i) {
    long long int x, y, l;
    cin >> x >> y >> l;
    H.push_back(seg(x, y, l));
  }
  long long int l = 0, r = 1000000010;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (check(mid, V, H))
      l = mid;
    else
      r = mid;
  }
  cout << l;
  return 0;
}
