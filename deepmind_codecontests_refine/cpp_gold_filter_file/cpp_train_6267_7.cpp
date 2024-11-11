#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using ii = pair<long long int, long long int>;
class prioritize {
 public:
  bool operator()(ii &p1, ii &p2) { return p1.first < p2.first; }
};
auto start_time = high_resolution_clock::now();
void time() { return; }
void ojudge() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return;
}
int main() {
  ojudge();
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int ones = 0;
  for (long long int i = 0; i < n; i++) ones += a[i];
  set<long long int> div;
  for (long long int i = 1; i * i <= ones; i++) {
    if (ones % i == 0) {
      if (i > 1) div.insert(i);
      if (ones / i > 1) div.insert(ones / i);
    }
  }
  vector<long long int> pos;
  long long int sz = 0, ans = 1e18;
  for (int k : div) {
    long long int curr = 0;
    for (long long int i = 0; i < n; i++) {
      if (a[i] == 0) continue;
      sz++;
      pos.push_back(i);
      if (sz == k) {
        long long int mid = pos[(sz + 1) / 2 - 1];
        while (sz > 0) {
          curr += abs(pos.back() - mid);
          pos.pop_back();
          sz--;
        }
        pos.clear();
      }
    }
    ans = min(ans, curr);
    pos.clear();
  }
  if (ans == 1e18) ans = -1;
  cout << ans << "\n";
  time();
  return 0;
}
