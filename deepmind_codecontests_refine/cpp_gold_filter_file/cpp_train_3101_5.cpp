#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll a,b,c;
  cin >> a >> b >> c;
  ll d =c-a-b;
  if(d>0 && d*d>4*a*b)	cout << "Yes";
  else cout << "No";
  return 0;
}