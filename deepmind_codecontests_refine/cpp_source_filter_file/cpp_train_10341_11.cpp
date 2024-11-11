#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000009;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> cavity_paths(n / 2 - 1, 1);
  long long p2 = 2;
  for (int i = 1; i < int(cavity_paths.size()); ++i) {
    cavity_paths[i] = (cavity_paths[i - 1] + p2) % MOD;
    p2 = (p2 << 1) % MOD;
  }
  vector<long long> left_paths(n / 2);
  left_paths[0] = 0;
  long long ways_here = 1;
  for (int i = 1; i < int(left_paths.size()); ++i) {
    ways_here = (ways_here * cavity_paths[i - 1]) % MOD;
    left_paths[i] = (left_paths[i - 1] + 4 * ways_here) % MOD;
  }
  cout << (2 *
           (1 + (2 + left_paths[n / 2 - 1]) * (2 + left_paths[n / 2 - 1]))) %
              MOD
       << endl;
}
