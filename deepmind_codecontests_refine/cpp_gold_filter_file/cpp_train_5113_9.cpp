#include <bits/stdc++.h>
using namespace std;
template <class T>
constexpr T const& cmin(T const& v) {
  return v;
}
template <class T, class... Args>
constexpr T const& cmin(T const& v0, T const& v1, Args const&... args) {
  return cmin(v0 < v1 ? v0 : v1, args...);
}
template <class T>
constexpr T const& cmax(T const& v) {
  return v;
}
template <class T, class... Args>
constexpr T const& cmax(T const& v0, T const& v1, Args const&... args) {
  return cmax(v0 > v1 ? v0 : v1, args...);
}
void solve() {}
const int MAX = 1001;
int a[MAX], b[MAX];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, s;
  scanf("%d", &n), scanf("%d", &s);
  for (int i = int(1); i <= int(n); ++i) scanf("%d", &a[i]);
  for (int i = int(1); i <= int(n); ++i) scanf("%d", &b[i]);
  if (!a[1]) puts("NO"), exit(0);
  if (a[s]) puts("YES"), exit(0);
  if (!b[s]) puts("NO"), exit(0);
  for (int i = int(n); i >= int(s + 1); --i) {
    if (a[i] & b[i]) puts("YES"), exit(0);
  }
  puts("NO"), exit(0);
}
