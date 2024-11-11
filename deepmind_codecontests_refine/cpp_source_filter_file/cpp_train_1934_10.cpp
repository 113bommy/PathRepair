#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10;
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2;
    for (int i = 1; i <= n / 2; i++) cout << 2 << " ";
    return 0;
  } else {
    cout << n / 2 << endl;
    for (int i = 1; i < n / 2; i++) cout << 2 << " ";
    cout << 3 << " ";
    cout << endl;
  }
}
