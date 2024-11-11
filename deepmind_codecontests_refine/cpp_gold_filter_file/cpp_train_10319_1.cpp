#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  long long t;
  cin >> t;
  for (int i = 0; i < n; i++) {
    long long b;
    cin >> b;
    a.push_back(b);
  }
  long long ans = 0;
  while (t > 0) {
    long long sum = 0;
    v.clear();
    bool ex = false;
    for (int i = 0; i < a.size(); i++) {
      if (t - a[i] >= 0) {
        ans++;
        v.push_back(a[i]);
        sum += a[i];
        t -= a[i];
        ex = true;
      }
    }
    if (!ex) break;
    ans += (t / sum) * (long long)v.size();
    t -= (t / sum) * sum;
    a.clear();
    a = v;
  }
  cout << ans;
  return 0;
}
