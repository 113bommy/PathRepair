#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>
#include <ext/rope>
 
#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define mp make_pair
#define pb push_back
#define LL long long
#define co complex<double>
#define fi first
#define se second
 
#define MAX 100005
#define AMAX 1500
#define MOD 1000000007
 
#define f(c,d) ((1<<(c))*(d))
 
using namespace std;
using namespace __gnu_cxx;

int t,n,m,x[605][605];
LL ta,tb,tc;

int main(){
	#ifdef LOCAL_PROJECT
	freopen("easy_contestant_package/sample.in","r",stdin);
    #endif
	scanf("%d",&t);
	F2(tt,1,t){
		scanf("%d%d",&n,&m);
		F1(a,0,n)F1(b,0,m)scanf("%d",&x[a][b]);
		ta=tb=0;
		F1(a,0,m){
			tc=0;
			F1(b,0,3)tc+=(x[b][a]-x[n-1-b][a])*(3-b);
			ta+=(tc*tc>500);
			tc=0;
			F1(b,0,3)tc+=(x[n/2-1-b][a]-x[n/2+b][a])*(3-b);
			tb+=(tc*tc>500);
		}
		//printf("%d %d %lld %lld ",n,m,ta,tb);
		printf(tb>ta?"YES\n":"NO\n");
	}
	#ifdef LOCAL_PROJECT
	while(1){}
    #endif
	#ifdef LOCAL_PROJECT
    system("pause");
    #endif
    return 0;
}
