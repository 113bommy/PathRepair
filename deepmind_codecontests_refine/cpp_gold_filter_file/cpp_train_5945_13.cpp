#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
void fre() {
  freopen("D:\\in.txt", "r", stdin);
  freopen("D:\\out.txt", "w", stdout);
}
vector<long long> v, va, vb;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a, b, ans = 1e18;
  cin >> a >> b;
  for (long long i = 1; i <= sqrt(a + b); i++) {
    if ((a + b) % i == 0) v.push_back(i);
    if (a % i == 0) va.push_back(i);
    if (b % i == 0) vb.push_back(i);
  }
  for (long long i = 0; i < v.size(); i++) {
    long long j;
    for (j = 0; j < va.size() && va[j] <= v[i]; j++) {
      if ((a + b) / v[i] >= a / va[j]) {
        ans = min(ans, (v[i] + (a + b) / v[i]) << 1);
        break;
      }
    }
    for (j = 0; j < vb.size() && vb[j] <= v[i]; j++) {
      if ((a + b) / v[i] >= b / vb[j]) {
        ans = min(ans, (v[i] + (a + b) / v[i]) << 1);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
