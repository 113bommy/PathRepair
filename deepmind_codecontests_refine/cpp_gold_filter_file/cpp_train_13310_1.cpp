#include <bits/stdc++.h>
using namespace std;
int main(){
	long long x; 
    double p;
    cin>>x>>p;
  if(x%2){cout<<setprecision(20)<<(((double)x+1)/2)/p*100<<endl;}
  else{ cout<<setprecision(20)<<(((double)x)/2)/p*100<<endl;}
}
