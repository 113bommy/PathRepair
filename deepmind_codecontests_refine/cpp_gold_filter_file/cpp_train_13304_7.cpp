#include<bits/stdc++.h>
using namespace std;

int main(){
	int L,R;cin>>L>>R;
	if(L%2019==0 or R%2019==0 or L/2019!=R/2019){puts("0");return 0;}
	int ans=2019;
	for(int i=L;i<=R;i++)
		for(int j=i+1;j<=R;j++)
			ans=min(1ll*ans,1ll*i*j%2019);
	printf("%d\n",ans);
	return 0;
}