#include <bits/stdc++.h>
using namespace std;

int main(){
  long long x,y;
  cin >> x >> y;
  int ans = (int)log2l(y/x) + 1;
  cout << ans << endl;
}
