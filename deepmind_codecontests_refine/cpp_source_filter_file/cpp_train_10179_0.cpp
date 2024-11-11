#include<bits/stdc++.h>
using namespace std;
using ll = long long
int main(){
  ll n;cin>>n;int a[10001]={0};
  for(int i=1;i*i<=10000;i++){
	for(int j=1;j*j<=10000;j++){
	  for(int k=1;k*k<=10000;k++){
	  	ll x=i*i+j*j+k*k+i*j+j*k+k*i;
	  	if(x<=10000)a[x]++;
      }
    }
  }
  for(int i=1;i<=n;i++){
    cout<<a[i]<<endl;
  }
}
