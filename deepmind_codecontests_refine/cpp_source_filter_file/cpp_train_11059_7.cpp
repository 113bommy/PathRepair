#include <bits/stdc++.h>
using namespace std;
set<long long> second[500005];
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    string second;
    cin >> second;
    long long n = second.size();
    vector<long long> v;
    long long in = 0, dis = n + 1;
    for (long long i = 0; i < n; i++) {
      if (second[i] == 'R') {
        dis = i + 1;
        in = i;
        break;
      }
    }
    v.push_back(dis);
    for (long long i = in + 1; i < n; i++) {
      if (in == 0) break;
      if (second[i] == 'R') {
        long long diff = i - in;
        in = i;
        v.push_back(diff);
      }
    }
    long long k = n + 1 - in;
    v.push_back(k);
    long long ans = 0;
    for (auto it : v) {
      ans = max(ans, it);
    }
    cout << ans << endl;
  }
}
