#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a=0,b=1;
	while(b<m){
		b=b+n-1;
		a++;
	}
	cout<<a;
}