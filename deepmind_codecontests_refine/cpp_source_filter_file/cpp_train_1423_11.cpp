#include <bits/stdc++.h>
using namespace std;
long long int shu[5050];
long long int flag[5050];
long long int other[5000];
long long int ans[5050];
struct D {
  vector<long long int> d;
  bool operator==(const D& o) {
    if (d.size() != o.d.size())
      return false;
    else
      for (long long int i = 0; i < d.size(); i++)
        if (d[i] != o.d[i]) return false;
    return true;
  }
} S[5050];
int main() {
  long long int n;
  cin >> n;
  long long int C = 0;
  for (long long int i = 0; i < n; i++) {
    scanf("%lld", &shu[i]);
    long long int N;
    S[i].d.clear();
    if (shu[i] < 0)
      N = sqrt(-shu[i] + 1);
    else
      N = sqrt(shu[i] + 1);
    for (long long int k = 2; k <= N; k++) {
      long long int have = 0;
      while (shu[i] % k == 0) {
        shu[i] /= k;
        have++;
      }
      if (have % 2 == 1) shu[i] *= k;
    }
  }
  for (long long int i = 0; i < n; i++) {
    if (!flag[i]) {
      flag[i] = ++C;
      for (long long int k = i + 1; k < n; k++) {
        if (shu[i] == shu[k]) flag[k] = C;
      }
    }
  }
  for (long long int i = 0; i < n; i++) {
    long long int Q = 0;
    long long int CA = i + 1;
    memset(other, 0, sizeof(other));
    for (long long int k = i; k < n; k++) {
      if (other[flag[k]] != CA && shu[k] != 0) {
        Q++;
        other[flag[k]] = CA;
      }
      if (Q != 0)
        ans[Q]++;
      else
        ans[1]++;
    }
  }
  for (long long int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
