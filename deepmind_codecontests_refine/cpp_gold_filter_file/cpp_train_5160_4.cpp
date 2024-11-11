#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
using namespace std;
int main() {
  long long n, x, y, z;
  cin >> n;
  cout << "? " << 1 << ' ' << 2 << endl;
  cin >> x;
  cout << "? " << 2 << ' ' << 3 << endl;
  cin >> y;
  cout << "? " << 1 << ' ' << 3 << endl;
  cin >> z;
  long long a1, a2, a3;
  a1 = ((x - y) + z) / 2;
  a2 = x - a1;
  a3 = y - a2;
  vector<long long> ans;
  ans.push_back(a1);
  ans.push_back(a2);
  ans.push_back(a3);
  long long l = a3;
  for (long long i = 3; i < n; i++) {
    cout << "? " << i << ' ' << i + 1 << endl;
    cin >> z;
    ans.push_back(z - l);
    l = z - l;
  }
  cout << "! ";
  for (auto i : ans) cout << i << ' ';
  return 0;
}
