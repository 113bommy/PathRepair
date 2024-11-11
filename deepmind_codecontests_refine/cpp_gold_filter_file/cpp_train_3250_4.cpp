#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
int beautyNum(int n) {
  vector<int> bn;
  int total = 0;
  for (int i = 1; i < 10 && i <= n; i++) {
    bn.push_back(i);
    total++;
  }
  if (n > 10) {
    int temp = 2;
    int tempTwo = 1;
    for (int i = 11; i <= n;) {
      for (int j = 1; j < 10; j++) {
        if (i * j > n) {
          break;
        }
        bn.push_back(i * j);
        total++;
      }
      tempTwo *= 10;
      temp = temp + tempTwo;
      i = bn[bn.size() - 1] + temp;
    }
  }
  return total;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t, n;
  cin >> t;
  while (t-- > 0) {
    cin >> n;
    cout << beautyNum(n) << "\n";
  }
}
