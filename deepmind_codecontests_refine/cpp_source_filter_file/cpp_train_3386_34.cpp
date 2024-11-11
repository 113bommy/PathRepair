#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e17;
const long long MAXN = 2e5 + 6;
long long a[MAXN], n;
long long ans = -INF;
long long prefs[MAXN], pref[MAXN];
struct line {
  long long a, b;
  long long intersect(line const& other) {
    if (other.a == a)
      return -INF;
    else
      return (long long)(other.b - b) / (a - other.a);
  }
  long long gety(long long x) { return (long long)a * x + b; }
};
struct ConvexHull {
  deque<line> dq;
  bool yoda(line l) {
    long long int1 = l.intersect(dq.back());
    long long int2 = dq.back().intersect(dq[dq.size() - 2]);
    long long int3 = l.intersect(dq[dq.size() - 2]);
    if (int1 == -INF) {
      if (l.b >= dq.back().b)
        return 1;
      else
        return 0;
    }
    if (int3 > int2)
      return 1;
    else
      return 0;
  }
  void add(line l) {
    while (dq.size() > 1 && yoda(l)) {
      dq.pop_back();
    }
    if (dq.empty())
      dq.push_back(l);
    else if (!(l.a == dq.back().a && l.b <= dq.back().b)) {
      dq.push_back(l);
    }
  }
  long long query(long long x) {
    long long l = 0, r = dq.size() - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (dq[mid].gety(x) < dq[mid + 1].gety(x)) {
        l = mid + 1;
      } else
        r = mid;
    }
    return dq[l].gety(x);
  }
} ch;
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
    prefs[i] = prefs[i - 1] + a[i] * i;
  }
  for (long long i = 1; i <= n; i++) {
    ch.add({(long long)i, (long long)-pref[i - 1]});
    ans = max(ans, (long long)prefs[(long long)n] - a[i] * i + pref[i - 1] +
                       ch.query((long long)a[i]));
  }
  ch.dq.clear();
  for (long long i = n; i >= 1; i--) {
    ch.add({(long long)i, (long long)-pref[i]});
    ans = max(ans, (long long)prefs[(long long)n] - a[i] * i + pref[i] +
                       ch.query((long long)a[i]));
  }
  cout << fixed << setprecision(0) << ans << endl;
  return 0;
}
