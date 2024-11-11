#include<bits/stdc++.h>
using namespace std;
int cnt1[100003],cnt2[100003],n,x,mx1=0,mx2=0,mx3=0,mx4=0,x1,x2;
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
			}else if(mx3<cnt1[x]){
				mx3=cnt1[x];
			}
		}
		else
		{
			cnt2[x]++;
			if(mx2<cnt2[x])
				mx2=cnt2[x],
				x2=x;
			}else if(mx4<cnt2[x]){
				mx4=cnt2[x];
			}
		}
	}
	if(x1!=x2)
		cout<<n-mx1-mx2;
	else
		cout<<n-max(mx1+mx4,mx2+mx3);
}
