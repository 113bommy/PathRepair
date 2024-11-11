#include <bits/stdc++.h>
using namespace std;

int main(){
	string S;
	cin >> S;
	int N=0,W=0,S=0,E=0;
	for(int i=0;i<S.size(),i++){
		if(S[i]=='N')N=1;
		if(S[i]=='W')W=10;
		if(S[i]=='S')S=-1;
		if(S[i]=='E')E=-10;
	}
	if(N+W+S+E==0)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}