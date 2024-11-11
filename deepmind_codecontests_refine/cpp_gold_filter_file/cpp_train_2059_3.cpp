#include<cstdio>
#include<iostream>
using namespace std;
long long a,b,v,w,t;
long long Abs(long long x){return x<0?-x:x;}
int main()
{
	cin>>a>>v>>b>>w>>t;
	if(Abs(a-b)<=(v-w)*t)cout<<"YES";
	else cout<<"NO";
}