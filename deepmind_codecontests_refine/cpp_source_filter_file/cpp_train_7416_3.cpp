#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<long long int> v;
  unordered_map<long long int, long long int> mapy;
  v.push_back(0);
  v.push_back(2);
  mapy[2] = 1;
  for (long long int i = 2; i <= 10000; i++) {
    v.push_back(((3 * (i * (i + 1))) / 2) - i);
    mapy[(((3 * (i * (i + 1))) / 2) - i)] = 1;
  }
  while (t--) {
    long long int n;
    cin >> n;
    ;
    long long int c = 0;
    while (n > 1) {
      auto f = lower_bound(v.begin(), v.end(), n);
      if (mapy[n] == 1) {
        c++;
        break;
      }
      long long int hj = f - v.begin();
      hj--;
      n = n - v[hj];
      c++;
    }
    cout << c << endl;
  }
}
