#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
const long long N = 2e3 + 5;
const long double pi = 3.14159265359;
void SRAND() {
  auto duration = std::chrono::system_clock::now().time_since_epoch();
  auto millis =
      std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  srand(millis);
}
long long n, a[N][N], l[N], st;
char c;
vector<pair<long long, long long> > ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) cin >> c, a[i][j] = c - '0';
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) cin >> c, a[i][j] ^= (c - '0');
  for (long long i = 0; i < n; i++) cin >> c, l[i] = c - '0';
  for (long long i = 0; i < n; i++)
    if (l[i]) {
      st = i;
      break;
    }
  for (long long i = 0; i < n; i++) {
    if (a[i][st]) {
      ans.push_back(make_pair(0, i));
      for (long long j = 0; j < n; j++) a[i][j] ^= l[j];
    }
  }
  for (long long j = 0; j < n; j++) {
    if (a[st][j]) {
      ans.push_back(make_pair(1, j));
      for (long long i = 0; i < n; i++) a[i][j] ^= l[i];
    }
  }
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++) {
      if (a[i][j]) {
        cout << "-1\n";
        return 0;
      }
    }
  cout << (long long)ans.size() << "\n";
  for (auto i : ans) {
    cout << (i.first ? "col " : "row ") << i.second << "\n";
  }
  return 0;
}
