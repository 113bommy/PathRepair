#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long s[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + n + 1, less<int>());
    for (int i = 1; i <= k + 1; i++) {
      sum += s[i];
    }
    cout << sum << endl;
  }
  return 0;
}
