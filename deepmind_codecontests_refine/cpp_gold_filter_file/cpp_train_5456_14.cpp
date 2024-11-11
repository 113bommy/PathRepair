#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6 + 5, inf = 1e9 + 7, B = 31;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  double Arr[n + n + 2];
  int sz = 0;
  double sum = 0.0;
  for (int i = 0; i < 2 * n; i++) {
    cin >> Arr[i];
    if (Arr[i] != ceil(Arr[i])) sum += (Arr[i] - floor(Arr[i])), sz++;
  }
  double res = inf;
  for (int i = max(sz - n, 0); i <= min(n, sz); i++)
    res = min(res, abs(sum - i));
  cout << fixed;
  cout << setprecision(3);
  cout << abs(res) << "\n";
  return 0;
}
