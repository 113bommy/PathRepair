#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  int sign = 1, minabs = 1e9 + 5, maid = -1;
  vector<int> zero, rest;
  for (int i = 0; i < a.size(); ++i) {
    cin >> a[i];
    if (a[i] < 0) {
      sign *= -1;
      minabs = min(minabs, -a[i]);
      if (minabs == -a[i]) maid = i;
    }
    if (a[i] == 0)
      zero.push_back(i + 1);
    else
      rest.push_back(i + 1);
  }
  if (sign == -1 && zero.size() == 0) {
    if (rest.size()) cout << "2 " << maid + 1 << endl;
    if (rest.size()) rest.erase(rest.begin() + maid);
    for (int i = 0; i < (int)rest.size() - 1; ++i)
      cout << "1 " << rest[i] << " " << rest[i + 1] << endl;
  }
  if (sign == 1 && zero.size() == 0)
    for (int i = 0; i < n - 1; ++i)
      cout << "1 " << i + 1 << " " << i + 2 << endl;
  if (sign == 1 && zero.size() > 0) {
    for (int i = 0; i < (int)zero.size() - 1; ++i) {
      cout << "1 " << zero[i] << " " << zero[i + 1] << endl;
    }
    if (zero.size() != n) cout << "2 " << zero.back() << endl;
    for (int i = 0; i < (int)rest.size() - 1; ++i)
      cout << "1 " << rest[i] << " " << rest[i + 1] << endl;
  }
  if (sign == -1 && zero.size() > 0) {
    for (int i = 0; i < (int)zero.size() - 1; ++i) {
      cout << "1 " << zero[i] << " " << zero[i + 1] << endl;
    }
    cout << "1 " << zero.back() << " " << maid + 1 << endl;
    if (zero.size() != n - 1) cout << "2 " << maid + 1 << endl;
    vector<int> rn;
    for (int i = 0; i < n; ++i)
      if (a[i] != 0 && i != maid) rn.push_back(i + 1);
    for (int i = 0; i < (int)rn.size() - 1; ++i) {
      cout << "1 " << rn[i] << " " << rn[i + 1] << "\n";
    }
  }
  return 0;
}
