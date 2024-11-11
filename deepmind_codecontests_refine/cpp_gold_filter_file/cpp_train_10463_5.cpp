#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> dyst(n);
  for (int i = 0; i < n; i++) cin >> dyst[i];
  sort(dyst.begin(), dyst.end());
  int malo = 1000000042;
  for (int i = 0; i < n / 2; i++) malo = min(dyst[i + n / 2] - dyst[i], malo);
  cout << malo;
  return 0;
}
