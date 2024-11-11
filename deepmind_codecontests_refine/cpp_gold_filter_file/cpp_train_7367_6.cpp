#include <bits/stdc++.h>
using namespace std;

int main() {
  int L, R, d; 
  cin >> L >> R >> d;
  int ans = R / d - (L - 1)/ d;
  cout << ans << endl;
}