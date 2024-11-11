#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T x, T y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    T f = x % y;
    x = y;
    y = f;
  }
  return x;
}
template <typename T>
pair<T, T> exgcd(T x, T y) {
  int sw = 0;
  if (x < y) sw = true, swap(x, y);
  pair<T, T> r = make_pair(1, 0);
  while (y > 0) {
    T f = x % y;
    r = make_pair(r.second, r.first - (x / y) * r.second);
    x = y;
    y = f;
  };
  if (sw) swap(r.first, r.second);
  return r;
}
int n, a, b, c, d, start, len;
const int maxn = 3e5 + 7;
long long et[maxn];
int eq[maxn];
long long d1[maxn];
long long d2[maxn];
template <int N, typename T = long long>
class OfflineRMQ {
 private:
  int _fr;
  int _to;
  T a[(N + 1) * 4];
  template <typename T2>
  void update(T2 arr[], int node, int fr, int to) {
    if (fr == to) {
      a[node] = arr[fr];
    } else {
      int m = (fr + to) / 2;
      update(arr, node * 2, fr, m);
      update(arr, node * 2 + 1, m + 1, to);
      a[node] = min(a[node * 2], a[node * 2 + 1]);
    }
  }
  T query(int node, int fr, int to, int x, int y) {
    if (to < x || fr > y) return numeric_limits<T>::max();
    if (x <= fr && to <= y) return a[node];
    int m = (fr + to) / 2;
    return min(query(node * 2, fr, m, x, y),
               query(node * 2 + 1, m + 1, to, x, y));
  }

 public:
  OfflineRMQ() {}
  template <typename T2>
  void prepare(T2 arr[], int fr, int to) {
    _fr = fr;
    _to = to;
    update(arr, 1, fr, to);
  }
  T query(int fr, int to) { return query(1, _fr, _to, fr, to); }
};
OfflineRMQ<maxn, long long> rmqd2;
int main(int argc, char *argv[]) {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> a >> b >> c >> d >> start >> len;
  {
    d1[0] = d2[0] = start;
    int res = -1;
    et[0] = -1;
    for (int i = 1; i <= n; i++) {
      cin >> et[i] >> eq[i];
      if (eq[i] == 0)
        d1[i] = d1[i - 1] - b, d2[i] = d2[i - 1] - d;
      else
        d1[i] = d1[i - 1] + a, d2[i] = d2[i - 1] + c;
      if (res == -1 && et[i] - len > et[i - 1]) res = et[i - 1] + 1;
    }
    if (res == -1) res = et[n] + 1;
    rmqd2.prepare(d2, 1, n);
    et[n + 1] = et[n] + 10ll * len;
    bool found = false;
    for (int i = 1, j1 = 1, j2 = 1; i <= n; i++) {
      if (d1[i - 1] >= 0 && et[i] - et[i - 1] >= len + (i == 1)) {
        res = et[i - 1] + 1;
        break;
      }
      long long min_start = max(et[i - 1] + 1, et[i] - len + 1);
      long long max_start = et[i];
      while (j1 < n && et[j1 + 1] - min_start < len) j1++;
      while (j2 < n && et[j2 + 1] - max_start < len) j2++;
      for (int j = j1; j <= j2; j++) {
        long long start_fr = max(min_start, et[j] - len + 1);
        long long start_to = min(max_start, et[j + 1] - len);
        if (start_fr <= start_to) {
          bool ok = true;
          long long new_min_ij = d1[i - 1] - d2[i - 1] + rmqd2.query(i, j);
          if (new_min_ij < 0) ok = false;
          if (ok) {
            res = start_fr;
            found = true;
            break;
          }
        }
      }
      if (found) break;
      if (d1[i] < 0) {
        res = -1;
        break;
      }
    }
    cout << res << endl;
  }
  return 0;
}
