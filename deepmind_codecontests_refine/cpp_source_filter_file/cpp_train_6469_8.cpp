#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int K = 60;
const int BIT = 19;
const int DIG = 10;
const int mod = 1e9 + 7;
int power(int a, long long b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = 1LL * res * a % mod;
    }
    a = 1LL * a * a % mod;
    b /= 2;
  }
  return res;
}
long long mseg[4 * N], seg[4 * N], lazy[4 * N], k[N], sk[N], a[N];
void pupdate(int node, int start, int end, int idx) {
  if (start > end || idx < start || end < idx) return;
  if (start == end) {
    seg[node] = a[start];
    mseg[node] = a[start] - k[start - 1];
    return;
  }
  int mid = (start + end) >> 1;
  pupdate(node << 1, start, mid, idx);
  pupdate(node << 1 | 1, mid + 1, end, idx);
  seg[node] = seg[node << 1] + seg[node << 1 | 1];
  mseg[node] = max(mseg[node << 1], mseg[node << 1 | 1]);
}
void update(int node, int start, int end, int l, int r, long long val) {
  if (lazy[node] != -1e18) {
    seg[node] = (sk[end] - sk[start - 1]) + lazy[node] * (end - start + 1);
    mseg[node] = lazy[node];
    if (start != end) {
      lazy[node << 1] = lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = -1e18;
  }
  if (start > end || r < start || end < l) return;
  if (l <= start && end <= r) {
    seg[node] = (sk[end] - sk[start - 1]) + val * (end - start + 1);
    mseg[node] = val;
    if (start != end) {
      lazy[node << 1] = lazy[node << 1 | 1] = val;
    }
    return;
  }
  int mid = (start + end) >> 1;
  update(node << 1, start, mid, l, r, val);
  update(node << 1 | 1, mid + 1, end, l, r, val);
  seg[node] = seg[node << 1] + seg[node << 1 | 1];
  mseg[node] = max(mseg[node << 1], mseg[node << 1 | 1]);
}
int find(int node, int start, int end, int l, int r, long long val) {
  if (l > r) return -1;
  if (start > end || r < start || end < l) return -1;
  if (lazy[node] != -1e18) {
    seg[node] = (sk[end] - sk[start - 1]) + lazy[node] * (end - start + 1);
    mseg[node] = lazy[node];
    if (start != end) {
      lazy[node << 1] = lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = -1e18;
  }
  if (l <= start && end <= r) {
    if (mseg[node] <= val) {
      return -1;
    }
    if (start == end) {
      return start;
    }
    int mid = (start + end) >> 1;
    if (mseg[node] > val) {
      return find(node << 1, start, mid, l, r, val);
    }
    return find(node << 1 | 1, mid + 1, end, l, r, val);
  }
  int mid = (start + end) >> 1;
  int idx = find(node << 1, start, mid, l, r, val);
  if (idx != -1) return idx;
  return find(node << 1 | 1, mid + 1, end, l, r, val);
}
long long query(int node, int start, int end, int l, int r) {
  if (lazy[node] != -1e18) {
    seg[node] = (sk[end] - sk[start - 1]) + lazy[node] * (end - start + 1);
    mseg[node] = lazy[node];
    if (start != end) {
      lazy[node << 1] = lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = -1e18;
  }
  if (start > end || r < start || end < l || l > r) return 0;
  if (l <= start && end <= r) {
    return seg[node];
  }
  int mid = (start + end) >> 1;
  return query(node << 1, start, mid, l, r) +
         query(node << 1 | 1, mid + 1, end, l, r);
}
int main() {
  int n, q;
  for (int i = 0; i < 4 * N; i++) {
    lazy[i] = -1e18;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    scanf("%lld", &k[i]);
    k[i] += k[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    sk[i] = k[i - 1] + sk[i - 1];
    pupdate(1, 1, n, i);
  }
  scanf("%d", &q);
  while (q--) {
    string s;
    long long x;
    int l, r, idx;
    cin >> s;
    if (s[0] == '+') {
      scanf("%d %lld", &idx, &x);
      long long val = query(1, 1, n, idx, idx);
      val += x;
      a[idx] = val;
      pupdate(1, 1, n, idx);
      int idxr = find(1, 1, n, idx + 1, n, a[idx] - k[idx - 1]);
      if (idxr == -1) {
        idxr = n + 1;
      }
      update(1, 1, n, idx + 1, idxr - 1, a[idx] - k[idx - 1]);
    } else {
      scanf("%d %d", &l, &r);
      printf("%lld\n", query(1, 1, n, l, r));
    }
  }
  return 0;
}
