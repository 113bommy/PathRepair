#include<iostream>
#include<string>
using namespace std;
string S,T;int n,p;
int main(){
	cin>>n>>S>>p;T=S;
	for(int i=0;i<S.size();i++){
		if(p>=1 && S[i]=='0'){T[i]='1';p--;}
	}
	for(int i=S.size()-1;i>=0;i--){
		if(p>=1 && S[i]=='1'){T[i]='0';p--;}
	}
	cout<<T<<endl;return 0;
}