#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  vector<int> a, b;
  int na, nb;
  cin >> na >> nb;
  int k, m;
  cin >> k >> m;
  for (int i = 0; i <= na - 1; i++) {
    int xx;
    cin >> xx;
    a.push_back(xx);
  }
  for (int i = 0; i <= nb - 1; i++) {
    int xx;
    cin >> xx;
    b.push_back(xx);
  }
  if (a[k - 1] < b[nb - m]) {
    cout << "YES\n";
  } else
    cout << "NO\n";
  return 0;
}
