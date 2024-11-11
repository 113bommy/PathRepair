#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, ans = 1;
  cin >> n;
  while (ans * 2 <= n) ans *= 2;
  cout << ans << endl;
}
