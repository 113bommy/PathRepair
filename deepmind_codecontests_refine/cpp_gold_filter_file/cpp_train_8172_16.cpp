#include <bits/stdc++.h>
long long int inf = 10e18;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, i, j, sum = 0;
  cin >> n;
  map<long long int, long long int> mp, mp2;
  while (n--) {
    cin >> i >> j;
    mp[i + j]++;
    mp2[i - j]++;
  }
  for (auto x : mp) {
    long long int m = x.second;
    sum += m * (m - 1) / 2;
  }
  for (auto x : mp2) {
    long long int m = x.second;
    sum += m * (m - 1) / 2;
  }
  cout << sum;
  return 0;
}
