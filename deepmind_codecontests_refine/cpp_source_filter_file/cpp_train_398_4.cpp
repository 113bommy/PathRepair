#include"bits/stdc++.h"
using namespace std;
int main(){
	string s;
	cin>>s;
	string t=s;
	reverse(s.begin(),s.end());
	for(auto &i:s){
		if(i=='b')
			i=d;
		else if(i=='d')
			i=b;
		else if(i=='p')
			i=q;
		else if(i=='q')
			i=p;
	}
	if(s==t)
		cout<<"Yes";
	else
		cout<<"No";
}
