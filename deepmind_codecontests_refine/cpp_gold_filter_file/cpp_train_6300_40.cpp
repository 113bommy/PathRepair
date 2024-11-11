#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long double> p(n);
  vector<long double> q(n);
  long double pall = 1;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i] /= 100.0;
    pall *= p[i];
    q[i] = 1 - p[i];
  }
  long double ans = n * pall;
  long double sum = pall;
  for (int i = 1; i < 1000000; ++i) {
    int idm = 0;
    long double nxt = sum / (1 - q[0]) * (1 - (q[0]) * (1 - p[0]));
    for (int j = 1; j < n; ++j) {
      if (nxt < sum / (1 - q[j]) * (1 - q[j] * (1 - p[j]))) {
        nxt = sum / (1 - q[j]) * (1 - q[j] * (1 - p[j]));
        idm = j;
      }
    }
    q[idm] *= (1 - p[idm]);
    ans += (n + i) * (nxt - sum);
    sum = nxt;
  }
  cout << fixed << setprecision(15) << ans << endl;
}
