#include<bits/stdc++.h>
using namespace std;

int main(){
	int h,n,k;
  	cin>>h>>n;
  	while(n--){
      	cin>>k;
    	h=h-k;
      	if(h==0 || h<0) {cout<<"Yes"; return 0;}
    }
  	cout<<"No";
}
