#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> v = {0, 0, 0, 1};
  for (int i = 0; i < n; i++) {
    v = {(v[1] + v[2] + v[3]) % 1000000007, (v[0] + v[2] + v[3]) % 1000000007,
         (v[0] + v[1] + v[3]) % 1000000007, (v[0] + v[1] + v[2]) % 1000000007};
  }
  cout << v[3] << endl;
}
