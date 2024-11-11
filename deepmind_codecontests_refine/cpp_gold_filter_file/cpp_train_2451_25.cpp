#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100 + 10;
const long long INF = 1000 * 1000 * 1000LL * 1000 * 10000;
int n, q, pt = 1, cnt;
vector<long long> ans;
set<pair<long long, long long> > s;
set<pair<long long, long long> >::iterator it1, it2;
long long po[100], a[N], sum[N * 4][2];
pair<long long, long long> chng[N * 4][2], minn[N * 4][2];
void shift(int ind, bool o, int b, int mid) {
  if (chng[ind][o].first) {
    chng[ind * 2][o] = chng[ind * 2 + 1][o] = chng[ind][o];
    minn[ind * 2][o] = make_pair(chng[ind][o].second, b);
    minn[ind * 2 + 1][o] = make_pair(chng[ind][o].second, mid);
    sum[ind * 2][o] = sum[ind * 2 + 1][o] = 0;
    chng[ind][o] = make_pair(0, 0);
  }
  long long t = sum[ind][o];
  sum[ind * 2][o] += t;
  sum[ind * 2 + 1][o] += t;
  minn[ind * 2][o].first += t;
  minn[ind * 2 + 1][o].first += t;
  sum[ind][o] = 0;
  return;
}
void add(int l, int r, pair<long long, long long> val, bool o, int b = 0,
         int e = n, int ind = 1) {
  if (l <= b && e <= r) {
    minn[ind][o].first += val.second;
    sum[ind][o] += val.second;
    return;
  }
  int mid = (b + e) / 2;
  shift(ind, o, b, mid);
  if (l < mid) add(l, r, val, o, b, mid, ind * 2);
  if (r > mid) add(l, r, val, o, mid, e, ind * 2 + 1);
  minn[ind][o] = min(minn[ind * 2][o], minn[ind * 2 + 1][o]);
  return;
}
void sett(int l, int r, pair<long long, long long> val, bool o, int b = 0,
          int e = n, int ind = 1) {
  if (l <= b && e <= r) {
    chng[ind][o] = val;
    sum[ind][o] = 0;
    minn[ind][o] = make_pair(val.second, b);
    return;
  }
  int mid = (b + e) / 2;
  shift(ind, o, b, mid);
  if (l < mid) sett(l, r, val, o, b, mid, ind * 2);
  if (r > mid) sett(l, r, val, o, mid, e, ind * 2 + 1);
  minn[ind][o] = min(minn[ind * 2][o], minn[ind * 2 + 1][o]);
}
pair<long long, long long> getmin(int l, int r, int b = 0, int e = n,
                                  int ind = 1) {
  pair<long long, long long> ret = make_pair(INF, INF);
  if (l <= b && e <= r) return minn[ind][0];
  int mid = (b + e) / 2;
  shift(ind, 0, b, mid);
  if (l < mid) ret = min(ret, getmin(l, r, b, mid, ind * 2));
  if (r > mid) ret = min(ret, getmin(l, r, mid, e, ind * 2 + 1));
  return ret;
}
long long get(int p, bool o, int b = 0, int e = n, int ind = 1) {
  if (b + 1 == e) return sum[ind][o] + chng[ind][o].second;
  int mid = (b + e) / 2;
  shift(ind, o, b, mid);
  if (p < mid) return get(p, o, b, mid, ind * 2);
  return get(p, o, mid, e, ind * 2 + 1);
}
long long type1(int x) {
  x--;
  return po[get(x, 1)] - get(x, 0);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  po[0] = 1;
  for (int i = 1; i <= 12; i++) po[i] = po[i - 1] * 42;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = 1 - a[i];
    sett(i, i + 1, make_pair(pt++, a[i]), 0);
    s.insert(make_pair(i, i + 1));
  }
  long long tp, x, l, r;
  for (int i = 0; i < q; i++) {
    cin >> tp;
    if (tp == 1) {
      cin >> x;
      ans.push_back(type1(x));
    } else {
      cin >> l >> r >> x;
      l--;
      if (tp == 2) {
        sett(l, r, make_pair(pt++, 1 - x), 0);
        sett(l, r, make_pair(pt++, 0), 1);
        s.insert(make_pair(l, r));
        it1 = it2 = s.find(make_pair(l, r));
        if (it1 != s.begin() && (*--it1).second > l) {
          pair<long long, long long> temp = *it1;
          s.erase(it1);
          it1 = s.find(make_pair(l, r));
          if (temp.first < l) s.insert(make_pair(temp.first, l));
          if (temp.second > r) s.insert(make_pair(r, temp.second));
        }
        it2++;
        while (it2 != s.end() && (*it2).first < r) {
          pair<long long, long long> temp = *it2;
          s.erase(it2);
          it2 = ++s.find(make_pair(l, r));
          if (temp.second > r) s.insert(make_pair(r, temp.second));
        }
      } else {
        bool flag = 1;
        pair<long long, long long> t1 = *--s.upper_bound(make_pair(l, n + 1));
        if (t1.first != l) {
          s.erase(t1);
          s.insert(make_pair(t1.first, l));
          s.insert(make_pair(l, t1.second));
        }
        pair<long long, long long> t2 = *--s.upper_bound(make_pair(r, n + 1));
        if (t2.first != r) {
          s.erase(t2);
          s.insert(make_pair(t2.first, r));
          if (t2.second != r) s.insert(make_pair(r, t2.second));
        }
        while (flag) {
          add(l, r, make_pair(pt++, -x), 0);
          pair<long long, long long> temp = getmin(l, r);
          while (temp.first < 0) {
            pair<long long, long long> seg =
                *--s.upper_bound(make_pair(temp.second, n + 1));
            int pnt = get(temp.second, 1);
            add(seg.first, seg.second, make_pair(pt++, po[pnt + 1] - po[pnt]),
                0);
            sett(seg.first, seg.second, make_pair(pt++, pnt + 1), 1);
            temp = getmin(l, r);
          }
          if (temp.first != 0) flag = 0;
        }
      }
    }
  }
  for (long long u : ans) cout << u << endl;
}
