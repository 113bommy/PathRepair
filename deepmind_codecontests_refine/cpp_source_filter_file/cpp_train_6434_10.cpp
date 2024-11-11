#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M;cin>>N>>M;
	int l=0,r=N+1;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		l=max(l,a);
		r=min(r,b);
	}if(l<=r){
		cout<<r-l+1<<endl;
	}else{
		cout<<0<<endl;
	}
}