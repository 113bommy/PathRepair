#include<iostream>

using namespace::std;

int  main(){
	int n;
  	cin>>n;
  	int ar[n],sum=0;
  	for(int i=0;i<n;i++)
      cin>>ar[i],sum+=ar[i];
  	int m;
  	cin>>m;
  	for(int j=0,l,r;j<m;j++){
      cin>>l<<r;
      cout<<sum+r-ar[l-1]<<'\n';
    }
}