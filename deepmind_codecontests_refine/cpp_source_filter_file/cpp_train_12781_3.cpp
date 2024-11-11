#include <bits/stdc++.h>
using namespace std;
int main() {
 int a, b, c, d;
  cin >> a >> b >> c >> d;
  for(int i=0;i<d;i++){
   if(a>b) b*=2;
   else c*=2;
  }
  if(c>b%%b>a) cout << "Yes" << endl;
  else cout << "No" << endl;
}
