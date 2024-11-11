#include<bits/stdc++.h>
using namespace std;
bitset<4000005> f;
int n,sum;
int main()
{
	cin>>n;
	f[0] = 1;
	for(int a,i=1;i<=n;i++)
		scanf("%d",&a),f|=(f<<a),sum+=a;
	int k=(sum+1)>>1;
	while(!f[k]) k++;
	cout<<k;
	return 0;
}
