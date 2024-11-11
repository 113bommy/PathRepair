#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int k, a, b;
  cin >> k >> a >> b;
  string s;
  cin >> s;
  long long int n = s.size();
  if (b * k < n || k * a > n) {
    cout << "No solution";
  } else {
    long long int z = n / k, i, v = 0, z1 = n % k;
    long long int p = z - 1;
    k = k - 1;
    while (k--) {
      cout << s.substr(v, z) << endl;
      v += z;
    }
    cout << s.substr(v);
  }
  return 0;
}
