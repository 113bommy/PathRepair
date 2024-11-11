#include <bits/stdc++.h>
using namespace std;
template <class T>
void p(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  cout << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  int i, n, x, k;
  cin >> n >> x >> k;
  vector<long long> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long res = 0LL;
  for (i = 0; i < n; i++) {
    long long t = (a[i] + x - 1) / x * x;
    t += (k - 1) * x;
    long long t1 = t + x;
    if (k == 0) {
      t = a[i];
    }
    vector<long long>::iterator it = lower_bound(a.begin(), a.end(), t);
    vector<long long>::iterator it1 = lower_bound(a.begin(), a.end(), t1);
    long long temp = (long long)(it1 - it);
    if (temp > 0) res += temp;
  }
  cout << res << endl;
  return 0;
}
