#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 1e6;
vector<long long> s;
void init() {
  int i = 1;
  s.push_back(1);
  while (i < 62) {
    s.push_back(((long long)1) << i);
    i++;
  }
}
int main() {
  int T;
  cin >> T;
  init();
  while (T--) {
    long long n, k;
    cin >> n >> k;
    long long t;
    t = lower_bound(s.begin(), s.end(), k) - s.begin();
    n -= s[t];
    long long kk = n / k;
    if (n % k != 0) kk += 1;
    t += kk;
    cout << t << endl;
  }
  return 0;
}
