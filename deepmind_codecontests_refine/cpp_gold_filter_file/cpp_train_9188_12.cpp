#include <bits/stdc++.h>
using namespace std;
void checkpoint1() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
bool comp(pair<long long, long long> &a, pair<long long, long long> &b) {
  if (a.first != b.first)
    return a.first < b.first;
  else {
    if (a.second > b.second)
      return b.second < a.second;
    else if (a.second < b.second)
      return a.second < b.second;
  }
  return a.first > b.first;
}
long long powe(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res %= 1000000007;
    }
    a *= a;
    a %= 1000000007;
    b >>= 1;
  }
  return res;
}
int main() {
  checkpoint1();
  long long n;
  cin >> n;
  long long ans[n + 1];
  bool vis[n + 1];
  memset(vis, 0, sizeof(vis));
  memset(ans, 0, sizeof(ans));
  set<long long> s;
  for (long long i = 1; i <= n; i++) s.insert(i);
  while (s.empty() == 0) {
    if (s.size() == 1) break;
    long long i1, i2;
    long long i = *s.begin();
    s.erase(s.begin());
    long long j = *s.begin();
    s.erase(s.begin());
    cout << "? " << i << " " << j << endl;
    cin >> i1;
    cout.flush();
    cout << "? " << j << " " << i << endl;
    cin >> i2;
    cout.flush();
    if (i1 > i2) {
      ans[i] = i1;
      vis[i1] = 1;
      s.insert(j);
    } else {
      ans[j] = i2;
      vis[i2] = 1;
      s.insert(i);
    }
  }
  long long fin = *s.begin();
  long long any = -1;
  for (long long ii = 1; ii <= n; ii++) {
    if (vis[ii] == 0) {
      any = ii;
      break;
    }
  }
  ans[fin] = any;
  cout << "! ";
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
