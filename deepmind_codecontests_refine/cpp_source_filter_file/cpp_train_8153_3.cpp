#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > sorted;
vector<pair<int, int> > ans;
int num[(1 << 17)], BIT[(1 << 17)];
long long BIT2[(1 << 17)];
int query(int loc) {
  loc += 5;
  int ret = 0;
  while (loc > 0) {
    ret += BIT[loc];
    loc -= (loc & -loc);
  }
  return ret;
}
void update(int loc, int inc) {
  loc += 5;
  while (loc < (1 << 17)) {
    BIT[loc] += inc;
    loc += (loc & -loc);
  }
}
int querySeg(int lo, int hi) {
  if (lo > hi) swap(lo, hi);
  return query(min(hi, (1 << 17) - 1)) - query(max(-1, lo - 1));
}
int binary(int ind, int dir) {
  int low = 0;
  int high = (1 << 17);
  int ret = ind;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (querySeg(ind + dir * mid, ind) == mid + 1) {
      ret = ind + dir * mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ret;
}
long long query2(int ind) {
  ind += 5;
  long long ret = 0;
  while (ind > 0) {
    ret += BIT2[ind];
    ind -= (ind & -ind);
  }
  return ret;
}
void update2(int ind, int inc) {
  ind += 5;
  while (ind < (1 << 17)) {
    BIT2[ind] += inc;
    ind += (ind & -ind);
  }
}
void updateSeg(int le, int ri, int inc) {
  update2(le, inc);
  update2(ri + 1, -inc);
}
long long queryPoint(int ind) { return query2(ind); }
int main() {
  int n;
  while (cin >> n) {
    sorted.clear();
    fill(BIT, BIT + (1 << 17), 0);
    fill(BIT2, BIT2 + (1 << 17), 0);
    for (int i = 0; i < n; i++) {
      cin >> num[i];
      sorted.push_back(make_pair(num[i], i));
      update(i, 1);
      updateSeg(i, i, num[i]);
    }
    ans.clear();
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i++) {
      int curind = sorted[i].second;
      int diff = queryPoint(curind);
      int le = binary(curind, -1);
      int ri = binary(curind, 1);
      updateSeg(le, ri, -diff);
      while (diff--) {
        ans.push_back(make_pair(le, ri));
      }
      update(i, -1);
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++) {
      printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
  }
  return 0;
}
