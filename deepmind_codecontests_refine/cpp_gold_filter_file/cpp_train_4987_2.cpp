#include<iostream>
#include<string>
using namespace std;
int n;string S,T;
int solve(string T){
	for(int i=0;i<T.size();i++){
		for(int j=1;j<T.size();j++){
			string U="";int c=i;
			while(c<T.size()){
				U+=T[c];c+=j;
				if(U==S)return 1;
			}
			if(U==S)return 1;
		}
	}
	return 0;
}
int main(){
	cin>>n>>S;int cnt=0;
	for(int i=0;i<n;i++){
		cin>>T;cnt+=solve(T);
	}
	cout<<cnt<<endl;
	return 0;
}