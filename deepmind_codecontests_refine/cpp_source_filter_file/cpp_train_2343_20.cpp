#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 100;
long long a[maxn];
long long t[maxn];
long long ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    t[a[i]]++;
  }
  for (int i = 0; i < n + 100; i++) {
    if (t[i] % 2 == 1) {
      ans++;
    }
    t[i + 1] += t[i] / 2;
  }
  cout << ans;
  return 0;
}
