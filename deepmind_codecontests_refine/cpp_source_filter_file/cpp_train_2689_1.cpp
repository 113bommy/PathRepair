#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 20;
int n,data[maxn],tmp[maxn];
int main(){
	cin >> n;
	for(int i = 1;i <= n;++i)scanf("%d",&data[i]);
	memcpy(tmp,data,sizeof(data));
	stable(tmp + 1,tmp + n + 1);
	int mid = tmp[n/2 + 1],mid_p = tmp[n/2];
	for(int i = 1;i <= n;++i)
		if(data[i] < mid)printf("%d\n",mid);
		else printf("%d\n",mid_p);
	return 0;
}
