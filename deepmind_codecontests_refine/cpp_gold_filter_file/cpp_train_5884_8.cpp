#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> v;
int main() {
  v.insert(make_pair(2, 1));
  long long int a, b, c, i, j, count = 0, val, vali, temp, counter = 2, ans = 0;
  cin >> a >> b;
  vali = 2;
  count = 2;
  while (vali <= log2(1e18) + 1) {
    val = pow(2, vali) - 1;
    temp = 1;
    vali++;
    long long int up = pow(2, vali - 2);
    while (temp < up) {
      v.insert(make_pair(val - temp, counter));
      temp *= 2;
      counter++;
    }
  }
  map<long long int, long long int>::iterator itr;
  for (itr = v.begin(); itr != v.end(); itr++) {
    if (itr->first >= a && itr->first <= b) ans++;
  }
  cout << ans;
  return 0;
}
