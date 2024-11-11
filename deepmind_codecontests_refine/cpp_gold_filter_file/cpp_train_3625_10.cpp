#include"bits/stdc++.h"
using namespace std;
int main(){
	string s;
	cin>>s;
	bool ch=true;
	if(s[0]!='A')
		ch=false;
	int cnt=0;
	for(int i=2;i!=s.size()-1;++i){
		if(s[i]=='C')
			++cnt;
		else if(isupper(s[i]))
			ch=false;
	}
	if(isupper(s[1]) || isupper(s.back()))
		ch=false;
	if(cnt!=1)
		ch=false;
	cout<<(ch ? "AC":"WA");
}


