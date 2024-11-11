#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
	cin>>a;
	for(int s=a.size()-1;s>=0;s--)
	b=b+a[s];
	for(int s=0;s<b.size();s++)
	{
		switch(b[s])
		{
			case 'p':b[s]='q';break;
			case 'q':b[s]='p';break;
			case 'b':b[s]='d';break;
			case 'd':b[s]='b';break;
		}
	}
	if(b==a)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
