#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,ans;cin >> n;
  ans=0;
  for (int i=0;i<n;i++) {
    int a,b;cin >> a >> b;
	if (a==b) {ans++;}
	else if (ans<3) {ans=0;}
  }
  if (ans>2) cout << "Yes" << endl;
  else cout << "No" MM endl;
}