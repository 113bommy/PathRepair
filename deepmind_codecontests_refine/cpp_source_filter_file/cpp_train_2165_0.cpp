#include<bits/stdc++.h>
using namespace std;
int n,a[200001],ans=1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]==ans)
			ans++;
	if(ans==1) 
		printf("-1");
	else
		printf("%d",n-h+1);
	return 0;
}