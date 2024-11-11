#include<bits/stdc++.h>
using namespace std;

int main(){
	string S,T;
  	cin>>S>>T;
  	T=T.erase(S.size())
  	if(S==T) cout<<"Yes";
  	else     cout<<"No" ;
  	return 0;
}