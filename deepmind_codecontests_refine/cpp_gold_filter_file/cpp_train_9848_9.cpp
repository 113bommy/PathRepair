#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, k;
  cin >> a >> k;
  long long b[a];
  for (int i = 0; i <= a; i++) {
    cin >> b[i];
  }
  sort(b, b + a);
  long long ans;
  for (int j = 0; j < k; j++) {
    ans += b[j];
  }
  cout << ans;
  return 0;
}
