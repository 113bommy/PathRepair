#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> ret;
  int cur = 1;
  for (int i = 0; i < n; i++)
    if (a[i] == cur) cur++, ret.push_back(i);
  cout << ret.size() << endl;
  for (auto it : ret) cout << it + 2001 << " ";
  cout << endl;
  return 0;
}
