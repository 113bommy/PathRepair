#include <bits/stdc++.h>
using namespace std;
int n, m, mp[10][10];
set<pair<int, int> > check;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, l, r;
  cin >> n >> l >> r;
  long long int ans = 0;
  for (long long int j = 0; j < l; j++) {
    ans += pow(2, j);
  }
  long long int min = ans + (n - l) * 1;
  for (long long int j = l; j < r; j++) {
    ans += pow(2, j);
  }
  long long int max = ans + (n - r) * pow(2, r - 1);
  cout << min << ' ' << max;
}
