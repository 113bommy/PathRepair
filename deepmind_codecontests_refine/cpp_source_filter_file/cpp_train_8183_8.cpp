#include <bits/stdc++.h>
using namespace std;
int t[300001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int b = n;
  cout << "1";
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    t[a] = 1;
    while (t[b]) b--;
    cout << i - (n - b) + 1;
  }
  return 0;
}
