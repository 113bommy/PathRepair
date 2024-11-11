#include <bits/stdc++.h>
using namespace std;
void machayenge() {
  long long int d;
  cin >> d;
  long long int n;
  cin >> n;
  long long int re[n];
  long long int ans = 0;
  for (long long int i = 0; i < n; ++i) {
    cin >> re[i];
    ans += d - re[i];
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  machayenge();
  return 0;
}
