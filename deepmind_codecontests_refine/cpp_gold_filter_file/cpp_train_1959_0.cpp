#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b%a==0)return a;
  return gcd(b%a,a);
}
int main(){
  int n,i;
  int a[111111];
  cin>>n;
  for(i=0;i<n;i++)cin>>a[i];
  for(i=1;i<n;i++)a[0]=gcd(a[0],a[i]);
  cout<<a[0];
  }