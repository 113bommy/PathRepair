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
const int N = 105;
char s1[N], s2[N];
int b, d, n, m, dp[N];
int main() {
  scanf("%d%d", &b, &d);
  scanf("%s%s", s1 + 1, s2 + 1);
  n = strlen(s1 + 1);
  m = strlen(s2 + 1);
  for (int i = 1; i <= m; i++) {
    int t = i, j = 1, c = 0;
    while (j <= n) {
      if (s1[j] == s2[t]) {
        t++;
        j++;
        c++;
        if (t == m + 1) t = 1;
      } else
        j++;
    }
    dp[i] = c;
  }
  int s = 1, ans = 0;
  LL tot = 0;
  for (int i = 1; i <= b; i++) {
    tot += dp[s];
    s = ((s + dp[s]) - 1) % m + 1;
    ans += tot / m;
    tot %= m;
  }
  printf("%d\n", ans / d);
}
