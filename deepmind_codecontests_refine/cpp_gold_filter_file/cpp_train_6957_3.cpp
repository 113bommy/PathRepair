#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	int ren;
	string ans="No";

	cin>>a>>b;

	ren=stoi(a+b);

	for(int i=0;i<1000;i++){
		if(ren==i*i){
			ans="Yes";
			break;
		}
	}
	cout<<ans;
}
