#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int N=0,W=0,S=0,E=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='N')N=1;
		if(s[i]=='W')W=10;
		if(s[i]=='S')S=-1;
		if(s[i]=='E')E=-10;
	}
	if(N+W+S+E==0)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}