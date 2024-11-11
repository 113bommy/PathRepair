#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAX = 1e6;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int a, b, f = 1;
  cin >> a >> b;
  vector<long long int> v;
  while (b % a) {
    v.push_back(b % a);
    b /= a;
  }
  v.push_back(0);
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i] != 0 && v[i] != 1 && v[i] != a && v[i] != a - 1) {
      f = 0;
      break;
    } else {
      if (v[i] == a || v[i] == a - 1) v[i + 1]++;
    }
  }
  if (f)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
