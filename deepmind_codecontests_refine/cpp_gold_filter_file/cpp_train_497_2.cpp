//金桥 傅思程
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,ans=0;
	char c;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>c;
		if(c=='R')ans++;
		else ans--;
	}
	if(ans>0)cout<<"Yes";
	else cout<<"No";
	return 0;
}