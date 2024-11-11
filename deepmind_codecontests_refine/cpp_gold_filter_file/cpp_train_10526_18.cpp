#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long MOD = 1e9 + 9;
vector<bool> used;
int main() {
  long long n;
  cin >> n;
  long long l = 0, r = 1e9 + 1;
  cout << 0 << " " << 1 << endl;
  string second;
  cin >> second;
  string a;
  for (int i = 1; i < n; i++) {
    long long m = (l + r) / 2;
    cout << m << " " << 1 << endl;
    cin >> a;
    if (a == second) {
      l = m;
    } else
      r = m;
  }
  cout << l << " " << 0 << " " << l + 1 << " " << 2 << endl;
  return 0;
}
