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
const int N = 2e5 + 7;
int n, k, a[N], b[N], ans, cc;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  for (int i = 1; i <= n; i++) {
    if (a[i] <= b[i]) cc++;
  }
  if (cc >= k) {
    for (int i = 1; i <= n; i++) ans += min(a[i], b[i]);
  } else {
    multiset<int> ts;
    for (int i = 1; i <= n; i++) {
      if (a[i] > b[i]) ts.insert(a[i] - b[i]);
    }
    for (int i = 1; i <= n; i++) {
      ans += min(a[i], b[i]);
    }
    for (int i = 0; i < k - cc; i++) {
      ans += *(ts.begin());
      ts.erase(ts.begin());
    }
  }
  printf("%d\n", ans);
}
