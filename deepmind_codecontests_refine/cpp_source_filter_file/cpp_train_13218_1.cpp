#include<bits/stdc++.h>
#define REP(i,n,N) for(int i=(n);i<(int)(N);i++)
#define p(s) cout<<(s)<<endl
#define ck(n,a,b) (a<=(n)&&(n)<=b
using namespace std;

string s,ans;
stack<int> st;
void bng(unsigned int pos,int diff){
	if(pos==s.size()) return;
	if(ck(s[pos],'A','Z')){
		ans+=(char) (s[pos]-'A'+diff)%26 + 'A';
		diff=0;
	}else if(s[pos]=='+'){
		diff++;
	}else if(s[pos]=='-'){
		diff--;
	}else if(s[pos]=='['){
		st.push(ans.size());
	}else if(s[pos]==']'){
		reverse(ans.begin()+st.top(),ans.end());
		st.pop();
	}else if(s[pos]=='?'){
		ans+='A';
		diff=0;
	}
	bng(pos+1,(diff+26)%26);
}

int main(){
	while(cin>>s){
		if(s==".") break;
		ans="";
		bng(0,0);
		p(ans);
	}
	return 0;
}