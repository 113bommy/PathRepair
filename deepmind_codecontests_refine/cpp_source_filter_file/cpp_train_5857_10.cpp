#include <bits/stdc++.h>
using namespace std;
const long long int INF = (long long int)1e9 + 5;
const unsigned long long int MOD = 1e9 + 9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout << std::fixed;
  std::cout.precision(6);
  int t;
  cin >> t;
  while (t--) {
    long long int n, r;
    cin >> n >> r;
    long long int s = 0;
    long long int mini = min(n - 1, r);
    s = mini * (mini + 1) / 2;
    if (r > n) s++;
    cout << s << "\n";
  }
  return 0;
}
