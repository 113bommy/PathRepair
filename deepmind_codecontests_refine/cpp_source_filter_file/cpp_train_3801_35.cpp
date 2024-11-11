#include <bits/stdc++.h>
using namespace std;
const int N = -1;
const long long INF = 1e9 + 19;
void read() {
  unsigned long long x;
  cin >> x;
  vector<pair<unsigned long long, unsigned long long> > answer;
  unsigned long long sum = 0;
  for (unsigned long long b = 1;; b++) {
    sum += (b - 1) * 1ll * (b - 1);
    unsigned long long tmp = x - sum;
    tmp += b * 1ll * (b - 1) * 1ll * b / 2;
    if (tmp <= 0) break;
    unsigned long long d = b * 1ll * b - b * 1ll * (b - 1) / 2;
    if (tmp / d <= b) break;
    if (tmp % d == 0) {
      answer.push_back(make_pair(b, tmp / d));
      if (b != tmp / d) answer.push_back(make_pair(tmp / d, b));
    }
  }
  sort(answer.begin(), answer.end());
  printf("%d\n", (int)answer.size());
  for (auto x : answer) printf("%lld %lld\n", x.first, x.second);
}
void solve() {}
void printAns() {}
void stress() {}
int main() {
  if (1) {
    int k = 1;
    for (int tt = 0; tt < k; tt++) {
      read();
      solve();
      printAns();
    }
  } else {
    stress();
  }
  return 0;
}
