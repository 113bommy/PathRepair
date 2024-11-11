#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	int ops = 0;
	while(b<=a){
		b = b*2;
		ops++;
	}
	while(c<=b){
		c = c*2;
		ops++;
	}
	if(ops<=k){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}