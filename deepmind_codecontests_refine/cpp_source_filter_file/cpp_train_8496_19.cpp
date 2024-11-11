#include <bits/stdc++.h>
using namespace std;
const double EPS = (double)1e-9;
const double PI = (double)acos(-1.0);
int irand(int lo, int hi) {
  return (((double)rand()) / (RAND_MAX + 1.0)) * (hi - lo + 1) + lo;
}
string toString(long long x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
long long toNumber(string S) {
  long long ret;
  sscanf(S.c_str(), "%lld", &ret);
  return ret;
}
const int INF = (int)2e9;
const long long MOD = (long long)1e9 + 7;
inline int getNext(int day, pair<int, int> dat) {
  if (day < dat.first) return dat.first;
  int mul = (day - dat.first - 1) / dat.second + 1;
  return dat.first + mul * dat.second;
}
int main() {
  int n;
  pair<int, int> dat[1005];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", &dat[i].first, &dat[i].second);
  int day = 0;
  for (int i = 0; i < n; i++)
    day = getNext(day + 1, dat[i]), fprintf(stderr, "   << %d\n", day);
  printf("%d\n", day);
  return 0;
}
