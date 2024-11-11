#include <bits/stdc++.h>
using namespace std;
const int N = 500000;
long long fast_pow(long long base, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * base) % 1000000007;
    base = (base * base) % 1000000007;
    n = n >> 1;
  }
  return res;
}
int pre[N + 5];
int main() {
  for (int i = 5; i <= N; i = i * 5) {
    for (int j = 1; i * j <= N; j++) {
      pre[i * j]++;
    }
  }
  for (int i = 1; i <= N; i++) {
    pre[i] += pre[i - 1];
  }
  int m;
  cin >> m;
  vector<int> ans;
  for (int i = 1; i <= N; i++) {
    if (pre[i] == m) {
      ans.push_back(i);
    }
  }
  int c = ans.size();
  sort(ans.begin(), ans.end());
  cout << c << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
