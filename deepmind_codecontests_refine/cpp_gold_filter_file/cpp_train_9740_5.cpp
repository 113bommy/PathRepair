#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100000;
const int MINVAL = -50000;
const int MAXVAL = +50000;
int n;
long long want;
int x[MAXN];
long long sumx[MAXN + 1];
long long allsums[MAXN + 1];
int nsums;
int sumidx[MAXN + 1];
int b1[MAXN + 2];
void b1mod(int idx, int by) {
  ++idx;
  while (idx <= nsums) {
    b1[idx] += by;
    idx += idx & -idx;
  }
}
int b1get(int idx) {
  if (idx == -1) return 0;
  ++idx;
  int ret = 0;
  while (idx > 0) {
    ret += b1[idx];
    idx -= idx & -idx;
  }
  return ret;
}
long long b2[MAXN + 2];
void b2mod(int idx, long long by) {
  ++idx;
  while (idx <= nsums) {
    b2[idx] += by;
    idx += idx & -idx;
  }
}
long long b2get(int idx) {
  if (idx == -1) return 0;
  ++idx;
  long long ret = 0;
  while (idx > 0) {
    ret += b2[idx];
    idx -= idx & -idx;
  }
  return ret;
}
int b3[MAXN + 2];
void b3mod(int idx, int val) {
  ++idx;
  while (idx <= nsums) {
    b3[idx] = min(b3[idx], val);
    idx += idx & -idx;
  }
}
int b3get(int idx) {
  if (idx == -1) return n;
  ++idx;
  int ret = n;
  while (idx > 0) {
    ret = min(ret, b3[idx]);
    idx -= idx & -idx;
  }
  return ret;
}
long long cntatleast(long long val) {
  long long ret = 0;
  for (int i = (1); i <= (nsums); ++i) b1[i] = 0;
  for (int i = (0); i <= (n); ++i) {
    long long cur = sumx[i] - val;
    int key = lower_bound(allsums, allsums + nsums, cur) - allsums;
    if (key >= nsums || allsums[key] > cur) --key;
    int cnt = b1get(key);
    ret += cnt;
    b1mod(sumidx[i], +1);
  }
  return ret;
}
long long calc_nth(long long nfixed) {
  long long l = (long long)MAXN * MINVAL - 1, h = (long long)MAXN * MAXVAL + 1;
  while (l + 1 < h) {
    long long m = l + (h - l) / 2;
    if (cntatleast(m) > nfixed)
      l = m;
    else
      h = m;
  }
  return l;
}
int e1[MAXN + 1], e3[MAXN + 1];
void init() {
  for (int i = (1); i <= (nsums); ++i) b1[i] = 0, b2[i] = 0, b3[i] = n;
  for (int i = (0); i <= (nsums); ++i) e1[i] = 0, e3[i] = n;
}
void calcbelow(long long val, int &cnt, long long &sum, int &idx) {
  int key = lower_bound(allsums, allsums + nsums, val) - allsums - 1;
  cnt = b1get(key);
  if (cnt != 0) sum = b2get(key);
  if (cnt != 0) idx = b3get(key);
}
void calceq(long long val, int &cnt, int &idx) {
  int key = lower_bound(allsums, allsums + nsums, val) - allsums;
  if (key >= nsums || allsums[key] != val) {
    cnt = 0;
    return;
  }
  cnt = e1[key];
  idx = e3[key];
}
void add(int key, int cnt, long long val, int idx) {
  b1mod(key, cnt);
  b2mod(key, val);
  b3mod(key, idx);
  ++e1[key];
  if (idx < e3[key]) e3[key] = idx;
}
int isfixed[MAXN + 1];
typedef struct Dyn {
  int a, b;
  long long val;
} Dyn;
bool operator<(const Dyn &p, const Dyn &q) {
  if (p.val != q.val) return p.val > q.val;
  if (p.b != q.b) return p.b < q.b;
  return p.a < q.a;
}
Dyn dyn[MAXN];
int ndyn;
long long process(long long mn, long long mx, long long nmndyn,
                  long long nmxfix) {
  long long ret = 0;
  init();
  set<pair<long long, int> > seen;
  ndyn = 0;
  for (int i = (0); i <= (n); ++i) isfixed[i] = 0;
  for (int i = (0); i <= (n); ++i) {
    int cntfix1;
    long long sumfix1;
    int minfix1;
    calcbelow(sumx[i] - mx, cntfix1, sumfix1, minfix1);
    if (cntfix1 > 0) {
      ret += cntfix1 * sumx[i] - sumfix1;
      ++isfixed[minfix1];
      --isfixed[i];
    }
    int cmx;
    int minmx;
    calceq(sumx[i] - mx, cmx, minmx);
    long long cntfix2 = min(nmxfix, (long long)cmx);
    cmx -= cntfix2;
    nmxfix -= cntfix2;
    if (cntfix2 > 0) {
      ret += cntfix2 * mx;
      ++isfixed[minmx];
      --isfixed[i];
    }
    long long cntdyn1 = mn != mx ? cmx : min((long long)cmx, nmndyn);
    if (mn == mx) nmndyn -= cntdyn1;
    if (cntdyn1 > 0) {
      for (int z = (0); z < (cntdyn1); ++z)
        dyn[ndyn].a = minmx, dyn[ndyn].b = i - 1, dyn[ndyn].val = mx, ++ndyn;
    }
    if (mn != mx) {
      for (set<pair<long long, int> >::iterator at =
               seen.lower_bound(make_pair(sumx[i] - mx + 1, INT_MIN));
           at != seen.end() && at->first < sumx[i] - mn; ++at) {
        dyn[ndyn].a = at->second, dyn[ndyn].b = i - 1,
        dyn[ndyn].val = sumx[i] - at->first, ++ndyn;
      }
      int cmn;
      int minmn;
      calceq(sumx[i] - mn, cmn, minmn);
      long long cntdyn3 = min(nmndyn, (long long)cmn);
      nmndyn -= cntdyn3;
      if (cntdyn3 > 0) {
        for (int z = (0); z < (cntdyn3); ++z)
          dyn[ndyn].a = minmn, dyn[ndyn].b = i - 1, dyn[ndyn].val = mn, ++ndyn;
      }
    }
    add(sumidx[i], 1, sumx[i], i);
    seen.insert(make_pair(sumx[i], i));
  }
  for (int i = (0); i < (n); ++i) isfixed[i + 1] += isfixed[i];
  sort(dyn, dyn + ndyn);
  return ret;
}
void rem1(multiset<long long> &use, multiset<long long> &avail,
          long long &sumuse, long long val) {
  multiset<long long>::iterator at = use.lower_bound(val);
  if (at != use.end() && *at == val) {
    sumuse -= val;
    use.erase(at);
    return;
  }
  at = avail.lower_bound(val);
  if (at != avail.end() && *at == val) {
    avail.erase(at);
    return;
  }
  assert(false);
}
void add1(multiset<long long> &use, multiset<long long> &avail,
          long long &sumuse, long long val) {
  if (((int)(use).size()) > 0) {
    multiset<long long>::iterator at = use.end();
    --at;
    if (val < *at) {
      use.insert(val);
      sumuse += val;
      return;
    }
  }
  avail.insert(val);
}
long long smn[2 * (MAXN + 1)], smx[2 * (MAXN + 1)];
void suminit() {
  for (int i = (0); i <= (n); ++i) smn[n + 1 + i] = smx[n + 1 + i] = sumx[i];
  for (int i = n; i >= 1; --i)
    smn[i] = min(smn[i << 1], smn[i << 1 | 1]),
    smx[i] = max(smx[i << 1], smx[i << 1 | 1]);
}
long long calcmnsum(int l, int r) {
  long long ret = LLONG_MAX;
  for (l += n + 1, r += n + 2; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = min(ret, smn[l++]);
    if (r & 1) ret = min(ret, smn[--r]);
  }
  return ret;
}
long long calcmxsum(int l, int r) {
  long long ret = LLONG_MIN;
  for (l += n + 1, r += n + 2; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ret = max(ret, smx[l++]);
    if (r & 1) ret = max(ret, smx[--r]);
  }
  return ret;
}
long long calcmnseg(int l, int r) {
  return sumx[r + 1] - sumx[l] - (calcmxsum(l, r + 1) - sumx[l]) -
         (sumx[r + 1] - calcmnsum(l, r + 1));
}
long long seg[MAXN];
void run() {
  scanf("%d%lld", &n, &want);
  if (want > (long long)n * (n + 1) / 2) want = (long long)n * (n + 1) / 2;
  for (int i = (0); i < (n); ++i) scanf("%d", &x[i]);
  sumx[0] = 0;
  for (int i = (0); i < (n); ++i) sumx[i + 1] = sumx[i] + x[i];
  nsums = 0;
  for (int i = (0); i <= (n); ++i) allsums[nsums++] = sumx[i];
  sort(allsums, allsums + nsums);
  nsums = unique(allsums, allsums + nsums) - allsums;
  for (int i = (0); i <= (n); ++i)
    sumidx[i] = lower_bound(allsums, allsums + nsums, sumx[i]) - allsums;
  long long nfixed = max(0LL, want - n);
  long long mn = calc_nth(want - 1), mx = calc_nth(nfixed);
  long long nmxfix = nfixed - cntatleast(mx + 1);
  long long nmndyn = want - cntatleast(mn + 1) - (mn == mx ? nmxfix : 0);
  long long sumfix = process(mn, mx, nmndyn, nmxfix);
  set<int> uncovered;
  for (int i = (0); i < (n); ++i)
    if (!isfixed[i]) uncovered.insert(i);
  multiset<long long> use, avail;
  long long sumuse = 0, mnpref = 0, mnsuff = 0;
  for (int i = (0); i < (n); ++i) seg[i] = -1;
  suminit();
  for (set<int>::iterator at = uncovered.begin(); at != uncovered.end(); ++at) {
    set<int>::iterator to = at;
    ++to;
    if (at == uncovered.begin()) mnpref = calcmnsum(0, *at);
    if (to == uncovered.end()) {
      mnsuff = sumx[n] - calcmxsum(*at + 1, n);
      continue;
    }
    long long mnseg = calcmnseg(*at + 1, *to - 1);
    seg[*at] = mnseg;
    add1(use, avail, sumuse, mnseg);
  }
  long long ret = LLONG_MIN, sumdyn = 0;
  for (int i = (0); i <= (ndyn); ++i) {
    if (((int)(uncovered).size()) == 0 && i == ndyn) {
      long long cur = sumfix + sumdyn;
      if (cur > ret) ret = cur;
    }
    if (i < ndyn && ndyn - i <= ((int)(uncovered).size())) {
      int nuse = ndyn - i - 1;
      while (((int)(use).size()) > nuse) {
        multiset<long long>::iterator at = use.end();
        --at;
        avail.insert(*at);
        sumuse -= *at;
        use.erase(at);
      }
      while (((int)(use).size()) < nuse && ((int)(avail).size()) > 0) {
        multiset<long long>::iterator at = avail.begin();
        use.insert(*at);
        sumuse += *at;
        avail.erase(at);
      }
      assert(((int)(use).size()) == nuse);
      long long cur = sumfix + sumdyn + (sumx[n] - mnpref - mnsuff - sumuse);
      if (cur > ret) ret = cur;
    }
    if (i < ndyn) {
      sumdyn += dyn[i].val;
      for (set<int>::iterator at = uncovered.lower_bound(dyn[i].a), tmp;
           at != uncovered.end() && *at <= dyn[i].b;
           tmp = at++, uncovered.erase(tmp)) {
        set<int>::iterator nxt = at;
        ++nxt;
        if (at == uncovered.begin()) {
          if (nxt != uncovered.end()) {
            rem1(use, avail, sumuse, seg[*at]);
            seg[*at] = -1;
            mnpref = calcmnsum(0, *nxt);
          }
        } else if (nxt == uncovered.end()) {
          set<int>::iterator prv = at;
          --prv;
          rem1(use, avail, sumuse, seg[*prv]);
          seg[*prv] = -1;
          mnsuff = sumx[n] - calcmxsum(*prv + 1, n);
        } else {
          set<int>::iterator prv = at;
          --prv;
          rem1(use, avail, sumuse, seg[*prv]);
          rem1(use, avail, sumuse, seg[*at]);
          long long mnseg = calcmnseg(*prv + 1, *nxt - 1);
          seg[*at] = -1;
          seg[*prv] = mnseg;
          add1(use, avail, sumuse, mnseg);
        }
      }
    }
  }
  printf("%lld\n", ret);
}
int main() {
  run();
  return 0;
}
