#include <bits/stdc++.h>
using namespace std;
int solve(int charge, int discharge) {
  if (discharge == 0)
    return 1;
  else if (discharge == -1)
    return 0;
  if (discharge <= 2)
    return 1 + solve(discharge + 1, charge - 2);
  else
    return 1 + solve(charge + 1, discharge - 2);
}
int main() {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n / 2; i++) {
    if (v[i] % 2 == 0) swap(v[i], v[n - i - 1]);
  }
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
