#include <bits/stdc++.h>
using namespace std;
long long dp[6][10001];
long long f(int q, long long l) {
  if (!q) return l;
  int k = min(10000LL, l);
  if (dp[q][k]) return l + dp[q][k];
  long long lasta = f(q - 1, l);
  for (int i = 1; i < k; i++) lasta = f(q - 1, lasta + 1);
  long long ret = f(q - 1, lasta + 1);
  dp[q][k] = ret - l;
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long l = 1;
  int q = 5;
  f(5, 1);
  while (1) {
    int k = min(10000LL, l);
    cout << k << ' ';
    vector<long long> a = {f(q - 1, l)};
    cout << a.back() << ' ';
    for (int i = 1; i < k; i++) {
      a.push_back(f(q - 1, a.back() + 1));
      cout << a.back() << ' ';
    }
    cout.flush();
    int resp;
    cin >> resp;
    if (resp < 0) return 0;
    if (resp) l = a[resp - 1] + 1;
    q--;
  }
}
