#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],cnt[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	int m=n;
	while (!cnt[m]) m--;
	int s=n-cnt[m];
	if (cnt[m-1]!=s)
		return puts("No"),0;
	if (m==n-1&&cnt[m]==n)
		return puts("Yes"),0;
	if (2*m-s>n||m<=s)
		return puts("No"),0; 
	puts("Yes");
	return 0;
}