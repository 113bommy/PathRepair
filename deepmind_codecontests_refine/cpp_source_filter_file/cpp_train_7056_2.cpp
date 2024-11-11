#include<bits/stdc++.h>
using namespace std;
string s,t,c;
int n,a,f;
int main(){
	cin>>s>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a==1) swap(s,T);
		if(a==2)
		{
			cin>>f>>c;
			if(f==1) t.push_back(c);
			if(f==2) s.push_back(c);
		}
	}
	reverse(t.begin(),t.end());
	cout<<t+s<<endl;
	return 0;
}