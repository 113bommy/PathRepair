#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  while (cin >> n >> k) {
    vector<long long> pp[100010];
    long long maxv = 0;
    for (long long i = 1; i <= n; i++) {
      long long t;
      scanf("%I64d", &t);
      pp[t].push_back(i);
      maxv = max(maxv, t);
    }
    long long status = 0;
    if (pp[0].size() != 1 || pp[1].size() > k) {
      cout << "-1" << endl;
      continue;
    }
    for (long long i = 2; i <= maxv; i++) {
      long long temp;
      temp = pp[i - 1].size() * (k);
      if (pp[i].size() > temp) {
        status = 1;
        break;
      }
    }
    if (status == 1) {
      cout << "-1" << endl;
      continue;
    }
    cout << n - 1 << endl;
    for (long long i = 0; i < pp[1].size(); i++)
      printf("%I64d %I64d\n", pp[0][0], pp[1][i]);
    for (long long i = 1; i < maxv; i++) {
      long long num = 0;
      long long l = 0;
      for (long long j = 0; j < pp[i + 1].size(); j++) {
        printf("%I64d %I64d\n", pp[i][l], pp[i + 1][j]);
        num++;
        if (num >= k - 1) {
          l++;
          num = 0;
        }
      }
    }
  }
}
