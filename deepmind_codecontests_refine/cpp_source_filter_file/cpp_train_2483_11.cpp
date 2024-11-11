#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int a,b,c,f=0;
	cin>>a>>b;
	set<int>s[100];
	r(i,m){
		cin>>c>>f;
		s[c].insert(f);
		s[f].insert(c);
	}
	r(i,n)cout<<s[i+1].size()<<endl;
}