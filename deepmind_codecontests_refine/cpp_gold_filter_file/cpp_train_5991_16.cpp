#include <bits/stdc++.h>
using namespace std;
const int n0 = 1 << 19;
const long long inf = 2e18;
int n, alive[n0];
array<int, 3> qr[n0];
long long ans[n0];
struct Line {
  long long k, b;
  long long val(long long x) { return k * x + b; }
  long long ip(const Line &l) { return (l.b - b + (k - l.k - 1)) / (k - l.k); }
  bool ok(Line &l1, Line &l2) { return ip(l2) < l1.ip(l2); }
};
struct Hull {
  vector<Line> v;
  int it;
  void add(Line &l) {
    while ((int)(v).size() > 1 && l.ok(v.back(), v[(int)(v).size() - 2]))
      v.pop_back();
    v.push_back(l);
  }
  long long get(long long x) {
    if (v.empty()) return -inf;
    while (it < (int)(v).size() - 1 && v[it + 1].val(x) >= v[it].val(x)) it++;
    return v[it].val(x);
  }
};
namespace DCP {
Hull t[n0 << 1];
void upd(int l, int r, Line ln) {
  r++;
  for (l += n0, r += n0; l < r; l /= 2, r /= 2) {
    if (l & 1) t[l++].add(ln);
    if (r & 1) t[--r].add(ln);
  }
}
long long get(int v, long long x) {
  long long res = -inf;
  for (v += n0; v > 0; v /= 2) res = max(res, t[v].get(x));
  return res;
}
}  // namespace DCP
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  vector<array<int, 4>> lines;
  vector<array<int, 2>> queries;
  for (int i = 0; i < n; i++) {
    cin >> qr[i][0] >> qr[i][1];
    if (qr[i][0] == 1) {
      alive[i] = 1;
      cin >> qr[i][2];
    }
    if (qr[i][0] == 2) {
      int j = qr[i][1];
      j--;
      alive[j] = 0;
      lines.push_back({qr[j][1], qr[j][2], j, i - 1});
    }
    if (qr[i][0] == 3) {
      queries.push_back({qr[i][1], i});
    }
  }
  for (int i = 0; i < n; i++)
    if (alive[i]) lines.push_back({qr[i][1], qr[i][2], i, n - 1});
  sort(begin(lines), end(lines));
  Line ln;
  for (auto &l : lines) {
    ln.k = l[0], ln.b = l[1];
    DCP::upd(l[2], l[3], ln);
  }
  sort(begin(queries), end(queries));
  for (auto &q : queries) {
    ans[q[1]] = DCP::get(q[1], q[0]);
  }
  for (int i = 0; i < n; i++) {
    if (qr[i][0] == 3) {
      if (ans[i] == -inf)
        cout << "EMPTY SET\n";
      else
        cout << ans[i] << '\n';
    }
  }
}
