#include <bits/stdc++.h>
using namespace std;
long long int c[200];
int main() {
  long long int t;
  cin >> t;
  long long int a[t], b[t];
  vector<pair<long long int, long long int> > vp;
  for (long long int i = 0; i < t; i++) cin >> a[i];
  for (long long int i = 0; i < t; i++) {
    cin >> b[i];
    vp.push_back(make_pair(b[i], i));
  }
  sort(a, a + t, greater<long long int>());
  sort(vp.begin(), vp.end());
  for (long long int i = 0; i < t; i++) b[vp.at(i).second] = a[i];
  for (long long int i = 0; i < t; i++) cout << b[i] << ' ';
  return 0;
}
