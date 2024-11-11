#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  vector<int> v;
  v.push_back(b);
  while (a < b) {
    if (b % 10 == 1)
      b /= 10;
    else if (b % 2 == 0)
      b >>= 1;
    else
      b = 0;
    v.push_back(b);
  }
  if (a != b) {
    cout << "No";
    return 0;
  }
  cout << "Yes\n";
  reverse((v).begin(), (v).end());
  cout << (int)v.size() << endl;
  for (int i = 0; i < (int)v.size(); i++) cout << v[i] << ' ';
  return 0;
}
