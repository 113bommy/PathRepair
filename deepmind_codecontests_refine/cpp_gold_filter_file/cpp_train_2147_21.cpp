#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
long long k[3], t[3], c[MAXN];
int n;
long long ans;
priority_queue<long long, vector<long long>, greater<long long> > Q[3];
int main() {
  for (int i = 0; i < (3); i++) cin >> k[i];
  for (int i = 0; i < (3); i++) cin >> t[i];
  cin >> n;
  ans = 0;
  for (int i = 0; i < (n); i++) {
    cin >> c[i];
    long long tmp = 0;
    for (int j = 0; j < (3); j++) {
      if (k[j] > 0) {
        tmp += t[j];
        Q[j].push(c[i] + tmp);
        k[j]--;
      } else {
        long long top = Q[j].top();
        Q[j].pop();
        if (top < tmp + c[i]) {
          tmp += t[j];
          Q[j].push(c[i] + tmp);
        } else {
          tmp += t[j] + top - (tmp + c[i]);
          Q[j].push(c[i] + tmp);
        }
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
