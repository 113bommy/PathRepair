#include <bits/stdc++.h>
using namespace std;
int n, k, m;
long long int sol;
int arr[10] = {0, 1, 1, 3, 16, 125, 1296, 16807, 262144};
int main() {
  cin >> n >> k;
  m = n - k;
  sol = (arr[k] * k) % 1000000007;
  for (int i = 0; i < m; i++) {
    sol = (sol * m) % 1000000007;
  }
  cout << sol << endl;
}
