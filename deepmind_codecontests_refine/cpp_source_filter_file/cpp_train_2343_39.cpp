#include <bits/stdc++.h>
const int OO = (long long)2e9;
const double eps = 1e-9;
const long long MAX = 1000005;
using namespace std;
long long n, a, sum = 0;
long long mp[MAX + 10];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    cin >> a;
    mp[a]++;
  }
  a = 0;
  while (a < MAX) {
    sum += mp[a] % 2;
    mp[a + 1] += mp[a] / 2;
    a++;
  }
  cout << sum << endl;
  return 0;
}
