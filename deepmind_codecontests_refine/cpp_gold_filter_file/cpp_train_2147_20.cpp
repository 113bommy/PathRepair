#include <bits/stdc++.h>
using namespace std;
long long n;
struct ddd {
  long long come;
  long long now;
  bool operator<(const ddd &ot) const { return now < ot.now; }
};
ddd s[111111];
void ans(long long k, long long t) {
  multiset<long long> busy;
  for (long long i = 0; i < n; i++) {
    if (busy.size() < k) {
      busy.insert(s[i].now + t);
      s[i].now = s[i].now + t;
    } else {
      long long nxt = *busy.begin();
      nxt = max(nxt, s[i].now);
      busy.erase(busy.begin());
      busy.insert(nxt + t);
      s[i].now = nxt + t;
    }
  }
  sort(s, s + n);
}
int main() {
  long long k1, k2, k3;
  cin >> k1 >> k2 >> k3;
  long long t1, t2, t3;
  cin >> t1 >> t2 >> t3;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> s[i].come;
    s[i].now = s[i].come;
  }
  ans(k1, t1);
  ans(k2, t2);
  ans(k3, t3);
  long long mx = 0;
  for (long long i = 0; i < n; i++) mx = max(mx, s[i].now - s[i].come);
  cout << mx << endl;
  return 0;
}
