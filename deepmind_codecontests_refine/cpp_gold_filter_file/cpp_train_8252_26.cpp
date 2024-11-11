#include <bits/stdc++.h>
using namespace std;
bool comp(int &a, int &b) { return abs(a) < abs(b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << n << "\n";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
  }
}
