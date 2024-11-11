#include <bits/stdc++.h>
using namespace std;
int n, cost[1009][1009], temp[1009][1009];
long long int a, b, x, sd, c, d = 0, f = INT_MAX, e, g, h, sf = 1000000007,
                              k = 0, lm, y, z;
int main() {
  cin >> a >> b;
  vector<long long int> vp;
  map<long long int, long long int> mp;
  for (long long int i = 0; i < b; i++) {
    cin >> x >> y >> z;
    if (mp[x] == 0 and mp[y] == 0 and mp[z] == 0) {
      mp[x] = 1;
      mp[y] = 2;
      mp[z] = 3;
    } else if (mp[x] == 1) {
      mp[y] = 2;
      mp[z] = 3;
    } else if (mp[x] == 2) {
      mp[y] = 1;
      mp[z] = 3;
    } else if (mp[x] == 3) {
      mp[y] = 2;
      mp[z] = 1;
    } else if (mp[y] == 1) {
      mp[x] = 2;
      mp[z] = 3;
    } else if (mp[y] == 2) {
      mp[x] = 1;
      mp[z] = 3;
    } else if (mp[y] == 3) {
      mp[x] = 1;
      mp[z] = 2;
    } else if (mp[z] == 1) {
      mp[x] = 2;
      mp[y] = 3;
    } else if (mp[z] == 2) {
      mp[x] = 1;
      mp[y] = 3;
    } else if (mp[z] == 3) {
      mp[x] = 1;
      mp[y] = 2;
    }
  }
  for (long long int i = 1; i <= a; i++) {
    cout << mp[i] << " ";
  }
}
