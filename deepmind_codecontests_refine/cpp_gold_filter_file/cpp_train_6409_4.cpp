#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%" PRId64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void sc() {}
template <typename T, typename... U>
void sc(T &head, U &...tail) {
  _R(head);
  sc(tail...);
}
vector<pair<long long, long long> > v;
long long q;
long long find(long long s) {}
int main() {
  int t = 1;
  while (t--) {
    long long n, m, k, s, x, i, j, a, b, res, req, used, sec, p;
    sc(n, m, k, x, s);
    res = n * x;
    int t1[200010][2], t2[200010][2];
    for (i = 0; i < m; i++) {
      sc(a);
      t1[i][0] = a;
    }
    for (i = 0; i < m; i++) {
      sc(b);
      t1[i][1] = b;
      v.push_back(make_pair(t1[i][1], t1[i][0]));
    }
    for (i = 0; i < k; i++) {
      sc(a);
      if (a > n) a = n;
      t2[i][0] = a;
    }
    for (i = 0; i < k; i++) {
      sc(b);
      t2[i][1] = b;
    }
    sort(v.begin(), v.end());
    j = v[0].second;
    for (i = 1; i < m; i++) {
      if (v[i].second > j)
        v[i].second = j;
      else
        j = v[i].second;
    }
    i = m - 1;
    j = k - 1;
    req = n;
    used = 0;
    res = n * x;
    p = 0;
    sec = x;
    while (i >= 0 && v[i].first > s) i--;
    if (i >= 0) {
      res = n * v[i].second;
      sec = v[i].second;
    }
    j = 0;
    while (i >= 0 && j < k) {
      if (v[i].first + t2[j][1] <= s) {
        if (res > (v[i].second * (n - t2[j][0])))
          res = (v[i].second * (n - t2[j][0]));
        j++;
      } else
        i--;
    }
    while (j < k) {
      if (t2[j][1] <= s && (n - t2[j][0]) * x < res) res = x * (n - t2[j][0]);
      j++;
    }
    cout << res;
  }
  return 0;
}
