#include<bits/stdc++.h>
using namespace std;
int cnt1[100003],cnt2[100003],n,x,mx1,mx2,x1,x2;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(i%2==0)
		{
			cnt1[x]++;
			if(mx1<cnt1[x])
				mx1=cnt1[x],
				x1=x;
		}
		else
		{
			cnt2[x]++;
			if(mx2<cnt2[x])
				mx2=cnt2[x],
				x2=x;
		}
	}
	sort(cnt1,cnt1+100003);
	sort(cnt2,cnt2+100003);
	if(x1!=x2)
		cout<<n-mx1-mx2;
	else
		cout<<n-max(mx1+cnt2[100001],mx2+cnt1[100001]);
}
