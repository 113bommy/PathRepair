#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  ;
}
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
namespace std {
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& a) {
  out << '(' << a.first << ',' << a.second << ')';
  return out;
}
}  // namespace std
long long int readL() {
  long long int res;
  scanf("%I64d", &res);
  return res;
}
void printL(long long int res) { printf("%I64d", res); }
const long long int INF = 1e18;
int n;
long long int pos[100005];
long long int stre[100005];
pair<long long int, long long int> range1[100005], range2[100005];
int m1, m2;
void solve(pair<long long int, long long int>* range, int& m) {
  range[m++] = make_pair(0, 0);
  stack<int> stk;
  stk.push(0);
  long long int seek;
  for (int i = 1; i < n + 1; ++i) {
    stk.push(i);
    seek = pos[i] + 1;
    ;
    ;
    while (stk.size() > 1) {
      int p = stk.top(), last;
      stk.pop();
      last = stk.top();
      long long int lim = stre[p] - (pos[p] - pos[last]) + pos[p];
      ;
      ;
      ;
      ;
      ;
      ;
      ;
      ;
      ;
      ;
      ;
      ;
      if (lim < pos[i + 1]) {
        if (seek <= lim) range[m++] = make_pair(seek, pos[p]);
        seek = max(seek, lim + 1);
      } else {
        stk.push(p);
        break;
      }
    }
    if (seek <= pos[i + 1]) range[m++] = make_pair(seek, pos[stk.top()]);
  }
}
long long int L;
long long int solve2(pair<long long int, long long int>* range, int m,
                     long long int p) {
  p = L - p;
  int q = lower_bound(range, range + m, make_pair(p + 1, -1ll)) - range;
  --q;
  return (p - range[q].second);
}
int main() {
  cin >> n;
  for (int i = 0; i < (n + 2); ++i) pos[i] = readL();
  for (int i = 0; i < (n); ++i) stre[i + 1] = readL() * 2;
  stre[0] = stre[n + 1] = INF;
  solve(range1, m1);
  ;
  ;
  debug(range1, range1 + m1);
  if (range1[m1 - 1].second > 0) {
    puts("0");
    return 0;
  }
  L = pos[n + 1];
  reverse(pos, pos + n + 2);
  for (int i = 0; i < (n + 2); ++i) pos[i] = L - pos[i];
  reverse(stre, stre + n + 2);
  solve(range2, m2);
  debug(range2, range2 + m2);
  long long int res = INF;
  for (int i = 0; i < (m1); ++i) {
    if (i)
      chmin(res, solve2(range2, m2, range1[i].first) + range1[i].first -
                     range1[i].second);
    if (i + 1 < m1)
      chmin(res, solve2(range2, m2, range1[i + 1].first - 1) +
                     range1[i + 1].first - 1 - range1[i].second);
    ;
    ;
  }
  for (int i = 0; i < (m2); ++i) {
    if (i)
      chmin(res, solve2(range1, m1, range2[i].first) + range2[i].first -
                     range2[i].second);
    if (i + 1 < m2)
      chmin(res, solve2(range1, m1, range2[i + 1].first - 1) +
                     range2[i + 1].first - 1 - range2[i].second);
    ;
    ;
  }
  printf("%f\n", (double)res / 2);
  return 0;
}
