#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

int n,a,b,c,l[10],ans=INF;

void dfs(int d, int x, int y, int z, int p){
	if(d<n){
		dfs(d+1,x,y,z,p,q,r);
		dfs(d+1,x+l[d],y,z,p+1);
		dfs(d+1,x,y+l[d],z,p+1);
		dfs(d+1,x,y,z+l[d],p+1);
	}else if(x&&y&&z){
		ans = min(ans,abs(x-a)+abs(y-b)+abs(z-c)+10*(p-3));
	}
}

int main(void){
	int i;
	cin >> n;
	cin >> a >> b >> c;
	for(i=0; i<n; ++i){
		cin >> l[i];
	}
	dfs(0,0,0,0,0);
	cout << ans << endl;
	return 0;
}
