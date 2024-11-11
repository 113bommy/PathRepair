#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, i, l, r, ans = 1000000000;
  cin >> n >> k;
  
  vector<int> x(n);
  for(i = 0; i < n; i++){
    cin >> x.at(i);
  }
  
  for(i = 0; i < n - k + 1; i++){
    l = x.at(i);
    r = x.at(i + k - 1);
    ans = min(ans, min(abs(r - l) + abs(l), abs(r - l) + abs(r)));
  }
  
  cout << ans << endl;
}