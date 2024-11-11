#include <bits/stdc++.h>
using namespace std;
vector<long long> seive(100002, 1);
void createSeive() {
  seive[0] = seive[1] = 0;
  for (long long i = 2; i * i <= 100002; i++) {
    if (seive[i] == 1) {
      long long cnt = 1;
      for (long long j = i * i; j <= 100002; j += i) {
        if (seive[j] == 1) {
          seive[j] = cnt + 1;
        }
      }
    }
  }
}
signed main() {
  createSeive();
  long long n;
  cin >> n;
  long long cnt = 0;
  vector<long long> v(n + 5, 0);
  unordered_map<long long, long long> mp;
  for (long long i = 1; i <= n; i++) {
    if (!v[i + 1]) {
      v[i + 1] = seive[i + 1];
      mp[seive[i + 1]] = 1;
    }
  }
  cout << mp.size() << "\n";
  for (long long i = 1; i <= n; i++) {
    if (v[i + 1]) cout << v[i + 1] << " ";
  }
}
