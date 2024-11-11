#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;	
int main()
{
	int n,m,q;
	vector<int> a[550];
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<m;i++){
		int l,r;
		scanf("%d%d",&(l),&(r));
		a[l].push_back(r);
	}		
 	for(int i=1;i<=500;i++){
 		sort(a[i].begin(),a[i].end());
	 }
	 for(int i=1;i<=q;i++){
	 	int ll,rr;
	 	int ans=0;
	 	scanf("%d%d",&(ll),&(rr));
	 	for(int j=ll;j<=rr;j++){
	 		ans+=upper_bound(a[j].begin(),a[j].end(),rr)-a[j].begin();	
		}
		printf("%d\n",ans);
	 }
}
