#include<bits/stdc++.h>
using namespace std; 
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int t=(a==b)+(a==c)+(b==c);
	if(t==1)cout<<"Yes";
	else cout<<"No"; 
	return 0;
}
