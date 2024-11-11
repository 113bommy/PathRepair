#include<Bits/stdc++.h>
using namespace std;
int ans;
string s,cmp="CODEFESTIVAL2016";
int main(){
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]!=cmp[i])ans++;
	printf("%d\n",ans);
	return 0;
}