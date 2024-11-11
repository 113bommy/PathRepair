#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;


int n;
int a[MAXN],b[MAXN];




void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&a[i],&b[i]);

	map<ll,int> L,R; ll dl=a[0],dr=a[0]; L[0]=+1; R[0]=+1; ll ret=0;
	FOR(i,1,n) {
		dl-=b[i]-a[i]; dr+=b[i-1]-a[i-1];
		ll lmx; { map<ll,int>::iterator it=L.end(); assert(it!=L.begin()); --it; lmx=dl+it->first; }
		ll rmn; { map<ll,int>::iterator it=R.begin(); assert(it!=R.end()); rmn=dr+it->first; }
		if(a[i]<lmx) {
			ret+=lmx-a[i];
			L[a[i]-dl]+=2;
			map<ll,int>::iterator it=L.end(); assert(it!=L.begin()); --it; assert(lmx==dl+it->first);
			--it->second; if(it->second==0) L.erase(it);
			R[lmx-dr]++;
		} else if(a[i]>rmn) {
			ret+=a[i]-rmn;
			R[a[i]-dr]+=2;
			map<ll,int>::iterator it=R.begin(); assert(it!=R.end()); rmn=dr+it->first; assert(rmn==dr+it->first);
			--it->second; if(it->second==0) R.erase(it);
			L[rmn-dl]++;
		} else {
			L[a[i]-dl]++;
			R[a[i]-dr]++;
		}
		//printf("ret=%lld\n",ret);
		//printf("L:"); for(map<ll,int>::iterator it=L.begin();it!=L.end();++it) printf(" %lld:%d",dl+it->first,it->second); puts("");
		//printf("R:"); for(map<ll,int>::iterator it=R.begin();it!=R.end();++it) printf(" %lld:%d",dr+it->first,it->second); puts("");
	}
	printf("%lld\n",cur);
}

int main() {
	run();
	return 0;
}
