#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int MAX=0,acgt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T'){
			acgt++;
		}else{
			MAX=max(MAX,acgt);
			acgt=0;
		}
	}
	MAX=max(MAX,acgt;)
	cout<<MAX;
	return 0;
}
