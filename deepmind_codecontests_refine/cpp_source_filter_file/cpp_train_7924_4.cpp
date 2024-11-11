#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void smn(T &a, const T &b) {
  if (b < a) a = b;
}
template <class T>
inline void smx(T &a, const T &b) {
  if (b > a) a = b;
}
template <class T>
inline T rev(const T &a) {
  T _ = a;
  reverse(_.begin(), _.end());
  return _;
}
const double eps = 1e-9;
const long double leps = 1e-14;
vector<int> lucky;
int p1, p2, v1, v2, k;
const int INF = (1u << 31) - 1;
void find(int d, int now) {
  if (d > 9) return;
  if (d) lucky.push_back(now);
  find(d + 1, now * 10 + 4);
  find(d + 1, now * 10 + 7);
}
double res;
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin >> p1 >> p2 >> v1 >> v2 >> k;
  find(0, 0);
  sort(lucky.begin(), lucky.end());
  for (int i = 0; i <= (int)lucky.size() - k; i++) {
    int last = (i == 0) ? 1 : lucky[i - 1] + 1;
    int next = (i + k == lucky.size() ? INF : lucky[i + k] - 1);
    if (p1 <= lucky[i] && v2 >= lucky[i + k - 1] && p2 >= last && v1 <= next)
      res += ((min(lucky[i], p2) - max(last, p1) + 1) / double(p2 - p1 + 1)) *
             ((min(next, v2) - max(lucky[i + k - 1], v1) + 1) /
              double(v2 - v1 + 1));
    if (v1 <= lucky[i] && p2 >= lucky[i + k - 1] && v2 >= last && p1 <= next)
      res += ((min(lucky[i], v2) - max(last, v1) + 1) / double(v2 - v1 + 1)) *
             ((min(next, p2) - max(lucky[i + k - 1], p1) + 1) /
              double(p2 - p1 + 1));
    if (k == 1 && lucky[i] >= p1 && lucky[i] <= p2 && lucky[i] >= v1 &&
        lucky[i] <= v2)
      res -= 1. / (p2 - p1 + 1) * 1. / (v2 - v1 + 1);
  }
  cout << fixed << setprecision(8) << res << '\n';
  return 0;
}
