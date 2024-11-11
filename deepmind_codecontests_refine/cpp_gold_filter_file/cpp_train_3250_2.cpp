#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
string yes = "YES\n";
string no = "NO\n";
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long j = 1; j <= 9; j++) {
      long long i = j;
      while (i <= n) {
        ans++;
        i = i * 10 + j;
      }
    }
    cout << ans << "\n";
  }
}
