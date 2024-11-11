#include <bits/stdc++.h>
using namespace std;
int main(){
int d,r,a,b;
cin>>a>>b;
d=a/b;
r=a%b;
cout<<d<<' '<<r<<' '<<setprecision(8)<<fixed<<1.0*a/b<<endl;
}
