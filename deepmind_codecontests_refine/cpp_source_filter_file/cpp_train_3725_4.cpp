#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;
int main() {
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  double e,f;
  e=(30*c-6*d)*PI()/180;
  f=a*a+b*b-2*a*b*cos(e);
  double g=sqrt(f);
  cout << fixed << setprecision(16);
  cout<<g<<endl;
  
}
