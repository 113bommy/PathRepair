#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
const double INF = 1e20;
int a[maxn];
bool nov[maxn];
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    int m = n / k;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= n; i++) nov[i] = true;
    double min_ans = INF, max_ans = 0;
    for (int i = 0; i < q; i++) {
      double sum = 0;
      int p;
      for (int i = 0; i < m; i++) {
        scanf("%d", &p);
        sum += a[p];
        nov[p] = false;
      }
      sum /= m;
      min_ans = min(min_ans, sum);
      max_ans = max(max_ans, sum);
    }
    priority_queue<double> x, y;
    int l = 0;
    for (int i = 1; i <= n; i++)
      if (nov[i]) {
        x.push(a[i]);
        y.push(-a[i]);
      } else
        l++;
    if (l / m < k) {
      if (x.size() >= m) {
        double tmp = 0;
        for (int i = 0; i < m; i++) {
          tmp += x.top();
          x.pop();
        }
        max_ans = max(max_ans, tmp / m);
      }
      if (y.size() >= m) {
        double tmp = 0;
        for (int i = 0; i < m; i++) {
          tmp -= y.top();
          y.pop();
        }
        min_ans = min(min_ans, tmp / m);
      }
    }
    printf("%.10f %.10f\n", min_ans, max_ans);
  }
}
