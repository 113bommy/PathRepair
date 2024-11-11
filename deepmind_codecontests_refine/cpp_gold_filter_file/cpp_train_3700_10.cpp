#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<long long, int> m;
  long long sum = 0;
  int ans = n - 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
    m[sum]++;
    ans = min(ans, n - m[sum]);
  }
  cout << ans << endl;
}
