#include <bits/stdc++.h>
using namespace std;
long long int a[100005 * 4], b[100005 * 4], N;
vector<long long int> st[100005 * 4];
bool comp(const long long int &t0, const long long int &t1) {
  if (a[t0] == a[t1]) return b[t0] < b[t1];
  return a[t0] < a[t1];
}
void make(long long int left, long long int right, long long int v) {
  if (left + 1 == right) {
    if (a[left] != -1) st[v].push_back(left);
    return;
  }
  long long int mid = (left + right) / 2;
  make(left, mid, v * 2);
  make(mid, right, v * 2 + 1);
  vector<long long int> vec;
  for (long long int i = 0;
       i < ((long long int)(((long long int)st[v * 2].size()))); i++)
    vec.push_back(st[v * 2][i]);
  for (long long int i = 0;
       i < ((long long int)(((long long int)st[v * 2 + 1].size()))); i++)
    vec.push_back(st[v * 2 + 1][i]);
  sort(vec.begin(), vec.end(), comp);
  vector<long long int> vv(((long long int)vec.size()), -1);
  long long int pos = 0;
  for (long long int i = 0; i < ((long long int)(((long long int)vec.size())));
       i++) {
    while (0 < pos) {
      bool ok = false;
      if (b[vv[pos - 1]] <= b[vec[i]]) ok = true;
      if (1 < pos && !ok) {
        long long int da = a[vv[pos - 2]] - a[vec[i]];
        long long int db = b[vec[i]] - b[vv[pos - 2]];
        long long int p1 = vv[pos - 1];
        long long int p2 = vv[pos - 2];
        if (a[p1] * db + b[p1] * da >= a[p2] * db + b[p2] * da) ok = true;
      }
      if (!ok) break;
      pos--;
    }
    vv[pos++] = vec[i];
  }
  for (long long int i = 0; i < ((long long int)(pos)); i++)
    st[v].push_back(vv[i]);
}
long long int search(long long int left, long long int right, long long int l,
                     long long int r, long long int v, long long int t) {
  if (r <= left || right <= l) return -1;
  if (l <= left && right <= r) {
    long long int low = 0, high = ((long long int)st[v].size());
    while (low + 1 < high) {
      long long int mid = (low + high) / 2;
      long long int t0 = a[st[v][mid - 1]] + b[st[v][mid - 1]] * t;
      long long int t1 = a[st[v][mid]] + b[st[v][mid]] * t;
      if (t0 < t1)
        low = mid;
      else
        high = mid;
    }
    return st[v][low];
  }
  long long int mid = (left + right) / 2;
  long long int res0 = search(left, mid, l, r, v * 2, t);
  long long int res1 = search(mid, right, l, r, v * 2 + 1, t);
  if (res0 == -1) return res1;
  if (res1 == -1) return res0;
  if (a[res0] + b[res0] * t < a[res1] + b[res1] * t) return res1;
  return res0;
}
int main() {
  long long int n, m, N;
  N = 1;
  while (N < 100005) N *= 2;
  memset(a, -1, sizeof(a));
  memset(b, -1, sizeof(b));
  cin >> n >> m;
  for (long long int i = 0; i < ((long long int)(n)); i++) cin >> a[i] >> b[i];
  make(0, N, 1);
  for (long long int i = 0; i < ((long long int)(m)); i++) {
    long long int t0, t1, t;
    cin >> t0 >> t1 >> t;
    cout << search(0, N, t0 - 1, t1, 1, t) + 1 << endl;
  }
}
