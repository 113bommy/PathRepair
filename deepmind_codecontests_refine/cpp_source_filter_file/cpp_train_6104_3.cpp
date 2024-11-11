#include <bits/stdc++.h>
using namespace std;
string f0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string part =
    "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
string part1 = "What are you doing while sending \"";
string part2 = "\"? Are you busy? Will you send \"";
const int NMAX = 100001;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
long long dp[NMAX];
void print(int n, long long k) {
  if (n == 0) {
    cout << f0[k - 1];
    return;
  }
  if (k <= part1.size()) {
    cout << part1[k - 1];
    return;
  }
  if (k <= part1.size() + dp[n - 1]) {
    print(n - 1, k - part1.size());
    return;
  }
  k -= part1.size();
  k -= dp[n - 1];
  if (k <= part2.size()) {
    cout << part2[k - 1];
    return;
  }
  if (k <= part2.size() + dp[n - 1]) {
    print(n - 1, k - part2.size());
    return;
  }
  k -= part2.size();
  k -= dp[n - 1];
  if (k == 0) {
    cout << "\"";
  } else {
    cout << "?";
  }
}
int main() {
  dp[0] = int(f0.size());
  for (int i = 1; i < NMAX; ++i) {
    dp[i] = 0LL + int(part.size()) + 1LL * 2 * dp[i - 1];
    if (dp[i] > INF) {
      dp[i] = INF;
    }
  }
  int q;
  cin >> q;
  int n;
  long long k;
  for (int test = 0; test < q; ++test) {
    cin >> n >> k;
    if (k > dp[n]) {
      cout << ".";
      continue;
    }
    print(n, k);
  }
  return 0;
}
