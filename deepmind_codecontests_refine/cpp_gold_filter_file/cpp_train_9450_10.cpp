#include<bits/stdc++.h>
#define ll long long
const int N=200005;
using namespace std;
ll k,n,a[N],r[N],b[N];
ll be,p=1,l,cnt;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(1)
	{
		if(b[a[p]]!=0)
		{
			be=b[a[p]];
			l=cnt-be+1;
			break;
		}
		r[++cnt]=a[p];
		b[a[p]]=cnt;
		p=a[p];
	}
	if(k<=be) cout<<r[k];
	else 
	{
		int s=(k-be)%l;
		cout<<r[s+be];
	}
    return 0;
}