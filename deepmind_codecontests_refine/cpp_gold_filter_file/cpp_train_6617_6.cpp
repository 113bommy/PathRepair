#include <bits/stdc++.h>
using namespace std;
struct data {
  int index, tp;
  double prof;
} dt[1000100];
bool comp(data a, data b) { return a.prof - b.prof > 1e-6; }
long long cnt[10], sm[10], a[1000100];
bool vis[1000100];
int main() {
  int n, n1, n2;
  cin >> n >> n1 >> n2;
  int ind = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dt[ind].index = i;
    dt[ind].prof = a[i] / (n1 * 1.00);
    dt[ind].tp = 0;
    ind++;
    dt[ind].index = i;
    dt[ind].prof = a[i] / (n2 * 1.00);
    dt[ind].tp = 1;
    ind++;
  }
  sort(dt + 1, dt + ind, comp);
  for (int i = 1; i < ind; i++) {
    if (dt[i].tp == 0) {
      if (!vis[dt[i].index] && cnt[0] < n1) {
        sm[0] += a[dt[i].index];
        cnt[0]++;
        vis[dt[i].index] = 1;
      }
    } else {
      if (!vis[dt[i].index] && cnt[1] < n2) {
        sm[1] += a[dt[i].index];
        cnt[1]++;
        vis[dt[i].index] = 1;
      }
    }
  }
  printf("%.9lf\n", (sm[0] / (n1 * 1.00) + sm[1] / (n2 * 1.00)));
}
