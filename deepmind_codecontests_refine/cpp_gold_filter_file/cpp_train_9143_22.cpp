#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int upper=min(b,d),lower=max(a,c);
  cout << max(0,upper-lower) << endl;
}