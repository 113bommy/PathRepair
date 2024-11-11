#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,k,S;
	
	
	cin >> n >> k >> S;
	for(int i=1;i<=k;i++){
		if(i!=1)
			cout << " ";
		cout << S;
	}
	if(S==1e9)
		S-=2;
	
	
	for(int i=k+1;i<=n;i++){
		cout << " " << S+1;
	}
	return 0;
}