#include<iostream>
using namespace std;
int coin[]={500,100,50,10,5,1};
int main() {int n,r,i;while(1){cin>>n;if(!n)break;n=1000-n,r=0;for(i=0;i<6;i++)r+=n/coin[i],n%=coin[i];cout<<r<<endl;}}