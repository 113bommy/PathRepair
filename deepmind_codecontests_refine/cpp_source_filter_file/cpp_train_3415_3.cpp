#include<iostream>
using namespace std;
int main(){
	int n,l,g,i,t=0;
	cin>>n>>l;
	g=l+n-1;
	for(i=0;i<n;i++)t+=l+i;
	if(l*g<=0){
		cout<<t;
	}else{
		if(l>0){
			cout<<t-l;
		}else{
			cout<<t-g;
		}
	}
}​