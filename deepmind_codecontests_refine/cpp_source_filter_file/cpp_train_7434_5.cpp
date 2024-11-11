#include <bits/stdc++.h>
using namespace std;
template <class T, class Type>
inline void reset(T begin, T end, Type fills = 0) {
  fill(begin, end, fills);
}
template <class T, class Type>
inline void reset(T stdcontainer, Type fills = 0) {
  fill(stdcontainer.begin(), stdcontainer.end(), fills);
}
template <class T, class Type>
inline void mfill(T container, int r, int c, Type fills = 0) {
  for (int i = 0; i < r; ++i) fill(container[i], container[i] + c, fills);
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d, m;
  long long total = 0;
  cin >> n >> d;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  cin >> m;
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n && m; ++i, --m) total += v[i];
  total -= d * m;
  cout << total << '\n';
  return 0;
}
