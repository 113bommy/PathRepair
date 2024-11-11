#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
string C, J;
long long rods[500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> rods[i];
  sort(rods + 1, rods + n + 1);
  long long sum = 0;
  for (int i = 1; i < n; i++) sum += rods[i];
  cout << rods[n] - sum;
}
