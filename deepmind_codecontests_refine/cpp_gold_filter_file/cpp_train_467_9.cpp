#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
double EPS = 1e-7;
int INF = 1000000000;
long long INFLL = 1000000000000000000LL;
int mx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int my[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int x[5005];
int sum[5005];
long double prob[5005];
long double prob2[10005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  int total = 0;
  for (int(i) = (0); (i) <= (n - 1); (i)++) {
    for (int(j) = (0); (j) <= (n - 1); (j)++) {
      if (i != j && x[i] > x[j]) {
        total++;
        sum[x[i] - x[j]]++;
      }
    }
  }
  for (int(i) = (1); (i) <= (5000); (i)++) {
    for (int(j) = (1); (j) <= (5000); (j)++) {
      prob2[i + j] += 1.0 * sum[i] * sum[j] / total / total;
    }
  }
  long double ans = 0.0;
  for (int(i) = (1); (i) <= (5000); (i)++) {
    double tot = 0.0;
    for (int(j) = (1); (j) <= (5000); (j)++) {
      if (i < j) {
        tot += sum[j];
      }
    }
    ans += prob2[i] * tot / total;
  }
  cout << setprecision(9) << ans << endl;
}
