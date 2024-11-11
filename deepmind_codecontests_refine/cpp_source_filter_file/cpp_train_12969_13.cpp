#include <bits/stdc++.h>
using namespace std;
long double pr[1002];
long double npr[1002];
int ans[1002];
int main(void) {
  int k, q;
  cin >> k >> q;
  vector<int> p;
  p.resize(q);
  for (int i = 0; i < q; ++i) {
    cin >> p[i];
  }
  pr[0] = 1;
  int n = k;
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 0; j < 1002; ++j) npr[j] = 0;
    for (int j = 0; j < 1001; ++j) {
      npr[j] += pr[j] * ((long double)j / n);
      npr[j + 1] += pr[j] * ((long double)(n - j) / n);
    }
    for (int j = 0; j < q; ++j) {
      if (ans[j] == 0) {
        if (npr[n] > p[j] / (long double)2000) {
          ans[j] = i;
        }
      }
    }
    swap(pr, npr);
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
}
