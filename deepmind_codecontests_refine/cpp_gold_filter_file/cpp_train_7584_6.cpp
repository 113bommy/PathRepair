#include <bits/stdc++.h>
using namespace std;

int main(){
	string S[3];
	cin >> S[0] >> S[1] >> S[2];
	int i=0;

	while(1){
		if(S[i].size()==0){
			cout << (char)(i+'A');
			return 0;
		}
		char c=S[i][0];
		S[i].erase(S[i].begin());
		i=c-'a';
	}

	return 0;
}