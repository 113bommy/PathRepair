#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const long long LINF = INF * (long long)INF;
const int MAX = 100 * 1000 + 47;
int T[MAX], V[MAX];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%d", V + i);
  for (int i = (0); i < (n); i++) scanf("%d", T + i);
  multiset<long long> S;
  long long add = 0;
  long long last = 0;
  for (int i = (0); i < (n); i++) {
    S.insert(V[i] - add);
    long long ans = 0;
    while (!S.empty() && *S.begin() + add <= T[i]) {
      long long v = *S.begin() + add;
      ans += v;
      S.erase(S.begin());
    }
    ans += T[i] * (int)S.size();
    add -= T[i];
    printf("%I64d ", ans);
  }
  return 0;
}
