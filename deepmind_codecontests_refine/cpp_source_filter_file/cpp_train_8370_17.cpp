#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void Print() { cout << endl; }
template <typename T1, typename... T>
void Print(const T1 &t1, const T &...t) {
  cout << t1 << " ";
  Print(t...);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class Iterator>
ostream &output_cantainer(ostream &os, Iterator first, Iterator last,
                          bool space = true) {
  if (space) {
    for (Iterator it = first; it != last; it++) {
      os << (*it) << ' ';
    }
    os << endl;
  } else
    for (Iterator it = first; it != last; it++) {
      os << (*it) << endl;
    }
  return os;
}
int n, m;
int w[100005];
bool ok(int p) {
  if (p % 2 == 1)
    return 1ll * p * (p - 1) / 2 + 1 <= n;
  else {
    LL cnt = 1ll * (p - 1) * (p - 2) / 2 + (p - 2) + (p - 2) / 2 + 1;
    return cnt <= n;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  int t;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &t, w + i);
  }
  sort(w, w + m, greater<int>());
  int l = 1, r = m;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  LL ans = 0;
  for (int i = 0; i < r; i++) ans += w[i];
  printf("%lld\n", ans);
}
