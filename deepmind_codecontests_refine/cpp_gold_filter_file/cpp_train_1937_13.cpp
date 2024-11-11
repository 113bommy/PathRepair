#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a;
  for (int e = 0; e < n; e++) {
    int y;
    cin >> y;
    a.push_back(y);
  };
  sort(a.begin(), a.end());
  int ct3 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[2]) ct3++;
  }
  if (a[0] == a[2])
    cout << (long long)(ct3) * (ct3 - 1) * (ct3 - 2) / 6 << "\n";
  else if (a[1] == a[2])
    cout << (long long)(0.5 * (ct3) * (ct3 - 1)) << "\n";
  else
    cout << ct3 << "\n";
  return 0;
}
