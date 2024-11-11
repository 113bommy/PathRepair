#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long INF = 1e17;
void solve() {
  long long n;
  cin >> n;
  long long arr[n], s = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    s += arr[i];
  }
  long long s1 = 0;
  for (long long i = 0; i < n; i++) {
    s1 += arr[i];
    if (s1 >= (s / 2)) {
      cout << i + 1 << endl;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 2;
  while (t--) {
    solve();
  }
  return (0);
}
