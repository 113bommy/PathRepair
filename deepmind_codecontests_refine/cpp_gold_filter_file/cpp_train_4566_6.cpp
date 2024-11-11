#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int w,a,b;
	cin>>w>>a>>b;
	if(abs(b-a)<=w){
		cout<<0;
		return 0;
	}
	cout<<abs(b-a)-w;
	return 0;
}