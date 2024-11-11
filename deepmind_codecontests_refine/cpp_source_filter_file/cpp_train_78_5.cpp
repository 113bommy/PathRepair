#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(string s,char pre){
	if(s.length()==n)cout<<s<<endl;
	else for(char i=97;i<=pre;i++)dfs(s+i,pre+(c==pre));
}
int main(){
	cin>>n;
	dfs("",97);
}