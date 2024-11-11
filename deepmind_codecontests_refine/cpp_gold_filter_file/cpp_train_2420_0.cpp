#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 2) {
      cout << 2 << endl;
      continue;
    }
    long long answer = pow(2, n);
    for (int i = 1; i < n / 2; i++) answer += pow(2, i);
    for (int i = n / 2; i < n; i++) answer -= pow(2, i);
    cout << answer << endl;
  }
  return 0;
}
