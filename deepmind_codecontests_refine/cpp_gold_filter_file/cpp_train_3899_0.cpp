#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int mod = 1e9 + 7;
template <class T>
inline void readInt(T &n) {
  n = 0;
  T ch = getchar();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
  n = n * sign;
}
bool vis[100005];
long long a[1005][105];
pair<long long, long long> pp[10005];
int main() {
  int flag = 0;
  long long mx;
  long long n, v;
  cin >> n >> v;
  mx = n;
  for (int i = ((int)(0)); i < ((int)(n)); i++) {
    long long tmp1, tmp2;
    readInt(tmp1);
    tmp1--;
    readInt(tmp2);
    pp[i].first = tmp1;
    pp[i].second = tmp2;
    mx = max(mx, tmp1);
  }
  long long ans = 0;
  sort(pp, pp + n);
  pp[n].first = 0;
  pp[n].second = 0;
  pp[n + 1].first = 0;
  pp[n + 1].second = 0;
  pp[n + 2].first = 0;
  pp[n + 2].second = 0;
  for (int i = ((int)(0)); i < ((int)(mx + 5)); i++) {
    long long q = v;
    long long take = 0;
    for (int j = ((int)(0)); j < ((int)(n + 1)); j++) {
      if (pp[j].first == i || pp[j].first == i - 1) {
        take = min(q, pp[j].second);
        q = q - take;
        ans += take;
        pp[j].second = pp[j].second - take;
      }
    }
  }
  cout << ans << endl;
}
