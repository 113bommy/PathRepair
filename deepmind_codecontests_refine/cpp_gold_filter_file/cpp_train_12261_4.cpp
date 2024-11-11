#include "bits/stdc++.h" 
using namespace std; 


int main(){
	string s;
	cin>>s;
int ind =-1,ans=1;
for(int i=0;i<3;i++) {
	if(s[i]=='R'){
		if(ind==-1) ind=i;
		else if(ind==(i-1)) ans++, ind=i;
	}
}
	cout<<(ind==-1?0:ans);
	
	return 0;
}
