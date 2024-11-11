#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> a >> b;
  if (a.size() < b.size()) {
    swap(a, b);
  }
  reverse(b.begin(), b.end());
  while (b.size() < a.size()) b.push_back('0');
  int mx = 0;
  for (int i = 0; i < a.size(); i++) mx = max(mx, a[i] - '0');
  for (int i = 0; i < b.size(); i++) mx = max(mx, b[i] - '0');
  reverse(a.begin(), a.end());
  int z = 0;
  for (int i = 0; i < a.size(); i++) {
    int x = a[i] - '0' + b[i] - '0' + z;
    if (x >= mx)
      z = 1;
    else
      z = 0;
  }
  cout << a.size() + 1;
  return 0;
}
