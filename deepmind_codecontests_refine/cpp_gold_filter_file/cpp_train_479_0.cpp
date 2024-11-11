#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200010;
int indexOf[MAX_N];
unsigned long long t[2 * MAX_N];
unsigned long long cnt[2 * MAX_N];
class Cmp {
 public:
  bool operator()(const pair<unsigned long long, int> &a,
                  const pair<unsigned long long, int> &b) const {
    return a.first < b.first;
  }
};
void buildTree(vector<pair<unsigned long long, int> > &a) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    t[n + i] = a[i].first;
    cnt[n + i] = 1;
  }
  for (int i = n - 1; i > 0; --i) {
    t[i] = t[2 * i] + t[2 * i + 1];
    cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
  }
}
void update(unsigned long long *t, int pos, unsigned long long val, int n) {
  pos += n;
  t[pos] = val;
  while (pos > 1) {
    t[pos / 2] = t[pos] + t[pos ^ 1];
    pos /= 2;
  }
}
unsigned long long query(unsigned long long *t, int l, int r, int n) {
  unsigned long long res = 0;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l % 2) {
      res += t[l++];
    }
    if (r % 2) {
      res += t[--r];
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<unsigned long long, int> > a;
  for (int i = 0; i < n; ++i) {
    unsigned long long x;
    cin >> x;
    a.push_back({x, i});
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    indexOf[a[i].second] = i;
  }
  buildTree(a);
  unsigned long long res[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    int idx = indexOf[i];
    update(t, idx, 0, n);
    update(cnt, idx, 0, n);
    auto next =
        upper_bound(a.begin(), a.end(), make_pair(a[idx].first + 1, 0), Cmp());
    int pos = next - a.begin();
    if (pos != n) {
      res[0] += query(t, pos, n, n);
      res[1] += query(cnt, pos, n, n) * a[idx].first;
    }
    auto prev =
        upper_bound(a.begin(), a.end(), make_pair(a[idx].first - 2, 0), Cmp());
    pos = prev - a.begin();
    if (pos - 1 >= 0 && pos != n) {
      res[0] += query(t, 0, pos, n);
      res[1] += query(cnt, 0, pos, n) * a[idx].first;
    }
  }
  unsigned long long r;
  string sign = "";
  if (res[0] >= res[1]) {
    r = res[0] - res[1];
  } else {
    r = res[1] - res[0];
    sign = "-";
  }
  cout << sign << r << endl;
  return 0;
}
