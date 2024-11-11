#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <set>
#include <map>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

char str[SIZE];
int rank[SIZE];
int sa[SIZE];
int lcp[SIZE];
PP tmp[SIZE];
int imos[SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	for(int i=0;i<n;i++) rank[i]=str[i]-'a';
	for(int k=1;k<=n;k<<=1)
	{
		for(int i=0;i<n;i++)
		{
			tmp[i]=PP(P(rank[i],i+k<n?rank[i+k]:-1),i);
		}
		sort(tmp,tmp+n);
		for(int i=0;i<n;)
		{
			int f=i;
			for(;i<n&&tmp[i].first==tmp[f].first;i++)
			{
				rank[tmp[i].second]=f;
			}
		}
	}
	for(int i=0;i<n;i++) sa[rank[i]]=i;
	int H=0;
	for(int i=0;i<n;i++)
	{
		if(H>0) H--;
		if(rank[i]==n-1) continue;
		int to=sa[rank[i]+1];
		while(i+H<n&&to+H<n&&str[i+H]==str[to+H]) H++;
		imos[H]++;
	}
	for(int i=n-1;i>=1;i--) imos[i]+=imos[i+1];
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		ret=max(ret,(n-i+1)-imos[i]);
	}
	printf("%d\n",ret);
	return 0;
}
