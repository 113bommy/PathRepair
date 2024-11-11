#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	char k[51][51]; 
	for(int i=0;i<a;i++){
		scanf("%s",k[i]);
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(k[i][j]=='#'){
				if(k[i-1][j]!='#'&&k[i][j-1]!='#'&&k[i+1][j]!='#'&&k[i][j+1]!='#'){
					cout<<"No";
					return 0;
				}
			}
		}
	}
	cout<<"Yes";
	return 0;
}