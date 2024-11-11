#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[505];
long long sum[300005];
long long en[505];
long long ans[300005];
long long in[300005];
bool mark[300005];
int n, m, a1, b1;
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%lld", in + i);
    }
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
      scanf("%d %d", &a1, &b1);
      a1--;
      if (b1 > 500) {
        long long s = 0;
        for (int i = a1; i < n; i += b1) {
          s += in[i];
        }
        mark[j] = 1;
        ans[j] = s;
      } else {
        pair<int, int> t;
        t.first = j;
        t.second = a1;
        a[b1].push_back(t);
      }
    }
    for (int i = 1; i <= 500; i++) {
      if (a[i].size() != 0) {
        int mi = i > n ? n : i;
        for (int j = 0; j < mi; j++) {
          sum[j] = in[j];
          if (j + i < n) {
            for (int k = j + i;; k += i) {
              sum[k] = sum[k - i] + in[k];
              if (k + i >= n) {
                en[j] = k;
                break;
              }
            }
          } else {
            en[j] = j;
          }
        }
        for (vector<pair<int, int> >::iterator it = a[i].begin();
             it != a[i].end(); it++) {
          int tmp = it->second % i;
          if (it->second >= i) {
            if (sum[en[tmp]] < sum[it->second - i]) {
              while (1)
                ;
            }
            ans[it->first] = sum[en[tmp]] - sum[it->second - i];
          } else {
            if (it->second < n) {
              ans[it->first] = sum[en[tmp]];
            } else {
              while (1)
                ;
            }
          }
        }
      }
    }
    for (int i = 0; i < m; i++) {
      if (ans[i] >= 0) {
        printf("%lld\n", ans[i]);
      } else {
        printf("%d\n", mark[i]);
      }
    }
  }
  return 0;
}
