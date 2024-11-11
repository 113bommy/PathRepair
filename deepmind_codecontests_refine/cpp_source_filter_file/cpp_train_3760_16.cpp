#include <bits/stdc++.h>
using namespace std;
long long int mod = (1ll << 63);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string second;
  cout << "1 1000000000" << endl;
  cin >> second;
  int l = -1, h = 1e9;
  for (int i = 0; i < n - 1; i++) {
    int mid = (l + h) / 2;
    cout << "1 " << mid << endl;
    string x;
    cin >> x;
    if (x == second) {
      h = mid;
    } else {
      l = mid;
    }
  }
  cout << "0 " << h << " 2 " << l << endl;
  return 0;
}
