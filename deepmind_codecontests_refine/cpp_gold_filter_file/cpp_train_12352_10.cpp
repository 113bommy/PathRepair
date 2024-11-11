#include <bits/stdc++.h>
using namespace std;
long long int inf = pow(10, 14), inf2 = pow(10, 12);
long long int n;
long long int arr[100005], diff[100005];
map<long long int, long long int> maxima, minima;
struct node {
  long long int max1, min1;
};
node tr[7 * 100005];
node findSum(long long int qs, long long int qe, long long int ss,
             long long int se, long long int si) {
  long long int mid = (ss + se) >> 1;
  node temp;
  temp.max1 = -inf, temp.min1 = inf;
  if (ss >= qs && se <= qe) {
    return tr[si];
  }
  if (ss > se || ss > qe || se < qs) return temp;
  node left, right;
  left = findSum(qs, qe, ss, mid, 2 * si + 1);
  right = findSum(qs, qe, mid + 1, se, 2 * si + 2);
  temp.max1 = max(left.max1, right.max1);
  temp.min1 = min(left.min1, right.min1);
  return temp;
}
node findSumUtil(long long int qs, long long int qe) {
  return findSum(qs, qe, 0, n - 2, 0);
}
void update(long long int ss, long long int se, long long int q,
            long long int val, long long int si) {
  if (se < q || ss > q || se < ss) return;
  if (ss == se) {
    tr[si].min1 = inf;
    tr[si].max1 = -inf;
    if (val > 0)
      tr[si].min1 = val;
    else if (val < 0)
      tr[si].max1 = val;
    else {
      tr[si].max1 = 0, tr[si].min1 = 0;
    }
    return;
  }
  long long int mid = (ss + se) >> 1;
  update(ss, mid, q, val, 2 * si + 1);
  update(mid + 1, se, q, val, 2 * si + 2);
  tr[si].max1 = max(tr[2 * si + 1].max1, tr[2 * si + 2].max1);
  tr[si].min1 = min(tr[2 * si + 1].min1, tr[2 * si + 2].min1);
}
void createUtil(long long int ss, long long int se, long long int si) {
  long long int mid = (ss + se) >> 1;
  if (ss == se) {
    tr[si].min1 = inf;
    tr[si].max1 = -inf;
    if (diff[ss] > 0)
      tr[si].min1 = diff[ss];
    else if (diff[ss] < 0)
      tr[si].max1 = diff[ss];
    else {
      tr[si].max1 = 0, tr[si].min1 = 0;
    }
    return;
  }
  if (ss > se) return;
  createUtil(ss, mid, 2 * si + 1);
  createUtil(mid + 1, se, 2 * si + 2);
  tr[si].max1 = max(tr[2 * si + 1].max1, tr[2 * si + 2].max1);
  tr[si].min1 = min(tr[2 * si + 1].min1, tr[2 * si + 2].min1);
}
void createSegment(long long int n) {
  long long int x = ceil(log(n) / log(2));
  createUtil(0, n - 1, 0);
}
long long int findMaxima(long long int l, long long int r) {
  auto it = maxima.upper_bound(l);
  if (it == maxima.end()) return -1;
  if (it->first >= r) return -1;
  return it->first;
}
long long int findMinima(long long int l, long long int r) {
  auto it = minima.upper_bound(l);
  if (it == minima.end()) return -1;
  if (it->first >= r) return -1;
  return it->first;
}
long long int case2(long long int l, long long int r, long long int x) {
  if (l > r) return -inf;
  node res = findSumUtil(l, r);
  long long int curr = -inf;
  if (res.max1 > (-inf2)) {
    curr = 2 * max(0ll, x - (long long int)(abs(res.max1)));
  }
  if (res.min1 < inf2) {
    curr = max(curr, 2 * max(0ll, x - res.min1));
  }
  return curr;
}
void updateMaxMin(long long int i) {
  if ((i == (n - 1)) or (i == 0)) return;
  maxima.erase(i);
  minima.erase(i);
  if (diff[i - 1] <= 0 && diff[i] >= 0) maxima[i];
  if (diff[i - 1] > 0 && diff[i] < 0) minima[i];
}
long long int changeSingle(long long int i, long long int x) {
  if (i == 0) {
    return abs(diff[i] + x) - abs(diff[i]);
  }
  if (i == (n - 1)) {
    return abs(diff[i - 1] - x) - abs(diff[i - 1]);
  }
  return abs(diff[i] + x) + abs(diff[i - 1] - x) - abs(diff[i]) -
         abs(diff[i - 1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (long long int i = 0; i < n; i += 1) cin >> arr[i];
  long long int ans = 0;
  for (long long int i = 0; i < n - 1; i += 1) {
    diff[i] = arr[i] - arr[i + 1];
    ans += abs(diff[i]);
  }
  for (long long int i = 1; i < n - 1; i += 1) {
    if (diff[i - 1] <= 0 && diff[i] >= 0) maxima[i];
    if (diff[i - 1] > 0 && diff[i] < 0) minima[i];
  }
  createSegment(n - 1);
  long long int q, a, l, r, x;
  cin >> q;
  while (q--) {
    cin >> a >> l >> r >> x;
    l--, r--;
    if (a == 2) {
      maxima.erase(l - 1);
      maxima.erase(r);
      minima.erase(l - 1);
      minima.erase(r);
      if (r != (n - 1)) {
        ans -= abs(diff[r]);
        diff[r] += x;
        ans += abs(diff[r]);
        update(0, n - 2, r, diff[r], 0);
      }
      if (l != 0) {
        ans -= abs(diff[l - 1]);
        diff[l - 1] -= x;
        ans += abs(diff[l - 1]);
        update(0, n - 2, l - 1, diff[l - 1], 0);
      }
      updateMaxMin(l);
      updateMaxMin(l - 1);
      updateMaxMin(r);
      updateMaxMin(r + 1);
    } else {
      if ((r - l) <= 100) {
        if (l == r) {
          cout << changeSingle(l, x) + ans << endl;
          continue;
        }
        long long int val = -inf;
        for (long long int i = l; i < r + 1; i += 1) {
          long long int curr = changeSingle(i, x);
          val = max(val, curr);
        }
        cout << val + ans << endl;
        continue;
      }
      long long int localMax = findMaxima(l, r);
      if (localMax != -1) {
        cout << (ans + 2 * x) << endl;
        continue;
      }
      long long int localMin = findMinima(l, r);
      if (localMin == -1) {
        long long int curr = case2(l + 1, r - 1, x);
        curr = max(curr, max(changeSingle(l, x), changeSingle(r, x)));
        for (long long int i = l; i < l + 5; i += 1)
          curr = max(curr, changeSingle(i, x));
        for (long long int j = r; j > (r - 5); j--)
          curr = max(curr, changeSingle(j, x));
        cout << curr + ans << endl;
      } else {
        long long int curr = -inf, i = localMin;
        long long int val1 = min(abs(diff[i - 1]), abs(diff[i]));
        long long int val2 = max(abs(diff[i - 1]), abs(diff[i]));
        curr = 2 * max(0ll, x - val2) - 2 * min(x, val1);
        curr = max(curr, max(changeSingle(l, x), changeSingle(r, x)));
        curr = max(curr, max(case2(l + 1, localMin - 2, x),
                             case2(localMin + 1, r - 1, x)));
        for (long long int i = l; i < l + 5; i += 1)
          curr = max(curr, changeSingle(i, x));
        for (long long int j = r; j > (r - 5); j--)
          curr = max(curr, changeSingle(j, x));
        cout << curr + ans << endl;
      }
    }
  }
  return 0;
}
