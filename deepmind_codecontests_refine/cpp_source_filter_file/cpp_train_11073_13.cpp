#include <bits/stdc++.h>
using namespace std;
void makra() {
  int n;
  cin >> n;
  if (n <= 2)
    cout << "-1\n";
  else {
    for (int i = 0; i < n; ++i) cout << i << " ";
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  while (tc--) {
    makra();
  }
  cerr << "Time elapsed:" << clock() / (long double)CLOCKS_PER_SEC << "sec"
       << endl;
  return 0;
}
