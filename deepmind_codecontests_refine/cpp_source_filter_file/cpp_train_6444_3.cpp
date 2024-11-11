#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ans = (a+b+c+d+e+f) - min(a, min(b, min(c, d)) - min(e, f);
  cout << ans << endl;
}
