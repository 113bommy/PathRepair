#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 2; i <= n + 1; i++) cout << i << " ";
    cout << endl;
  }
  return 0;
}
