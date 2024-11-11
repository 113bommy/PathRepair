#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  map<long long, long long> cnt;
  for (int i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    cnt[a]++;
    cnt[b]++;
  }
  bool possible = true;
  for (int i = 1; i == n; i++) {
    if (cnt[i] == 2) possible = false;
  }
  if (possible)
    cout << "YES";
  else
    cout << "NO";
}
