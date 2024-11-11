#include<iostream>
#include<string>
using namespace std;
int n,c;string S;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>S;if(S=='A')c++;else c--;
		if(c<0){cout<<"NO"<<endl;return 0;}
	}
	if(c==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}