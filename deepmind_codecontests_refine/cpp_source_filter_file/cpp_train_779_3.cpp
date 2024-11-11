#include <bits/stdc++.h>
using namespace std;
long long comp(pair<pair<long long, long long>, pair<long long, long long>> a,
               pair<pair<long long, long long>, pair<long long, long long>> b) {
  return a.second.first < b.second.first;
}
set<pair<long long, long long>> sr;
long long n, m, tr[800555];
pair<long long, long long> br[200005];
pair<pair<long long, long long>, pair<long long, long long>> ar[200005];
long long query(long long idx, long long l, long long r, long long pos);
void upd(long long idx, long long l, long long r, long long pos, long long val);
int main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &ar[i].first.first, &ar[i].first.second);
    ar[i].first.second += ar[i].first.first;
    ar[i].second.first = i;
    ar[i].second.second = 0;
  }
  sort(ar, ar + n);
  for (int i = 0; i < n; i++) {
    upd(0, 0, n - 1, i, ar[i].first.second);
  }
  for (int i = 0; i < m; i++) {
    long long pos, size_;
    scanf("%lld %lld", &pos, &size_);
    long long x = query(0, 0, n - 1, pos);
    if (x == -1) {
      sr.insert(make_pair(pos, size_));
      continue;
    }
    long long st = ar[x].first.first, end = ar[x].first.second;
    if (st <= pos && pos <= end) {
      end += size_;
      ar[x].second.second++;
      while (!sr.empty()) {
        auto itr = sr.lower_bound(make_pair(st, 0));
        if (itr == sr.end()) break;
        long long pos = (*itr).first, size_ = (*itr).second;
        if (st <= pos && pos <= end) {
          sr.erase(itr);
          end += size_;
          ar[x].second.second++;
        } else
          break;
      }
    }
    upd(0, 0, n - 1, x, end);
    ar[x].first.second = end;
  }
  sort(ar, ar + n, comp);
  for (int i = 0; i < n; i++)
    printf("%lld %lld\n", ar[i].second.second,
           (ar[i].first.second - ar[i].first.first));
}
long long query(long long idx, long long l, long long r, long long pos) {
  if (ar[l].first.first > pos || tr[idx] < pos) return -1;
  if (l == r) return l;
  long long mid = (l + r) / 2;
  int x = query(2 * idx + 1, l, mid, pos);
  if (x == -1) return query(2 * idx + 2, mid + 1, r, pos);
  return x;
}
void upd(long long idx, long long l, long long r, long long pos,
         long long val) {
  if (pos < l || pos > r) return;
  if (l == r) {
    tr[idx] = val;
    return;
  }
  long long mid = (l + r) / 2;
  upd(2 * idx + 1, l, mid, pos, val);
  upd(2 * idx + 2, mid + 1, r, pos, val);
  tr[idx] = max(tr[2 * idx + 1], tr[2 * idx + 2]);
}
