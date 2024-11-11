#include <bits/stdc++.h>
using namespace std;
pair<string,int> a[100];
int main(){
	int t=0,g;
	string f,b;
	while(cin>>a[t].first>>a[t].second)t++;
	sort(a,a+t);
	b=a[0].first
	cout<<b<<endl<<a[0].second;
	for(int i=1;i<t;i++){
		bool n=0;
		f=a[i].first,g=a[i].second;
		if(i)if(f==b)n=1;
		if(n)cout<<" "<<g;
		else cout<<endl<<f<<endl<<g;
		b=f;
	}
	cout<<endl;
	return 0;
}