#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int arr[2 * n];
    int mx = 0;
    vector<int> ind;
    for (int i = 0; i < 2 * n; i++) {
      cin >> arr[i];
      if (arr[i] > mx) {
        mx = arr[i];
        ind.push_back(i);
      }
    }
    ind.push_back(2 * n);
    vector<int> lens;
    for (int i = 1; i < ind.size(); i++) {
      lens.push_back(ind[i] - ind[i - 1]);
    }
    bitset<2005> b;
    b[0] = 1;
    for (auto e : lens) b = (b | (b << e));
    if (b[n] == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
