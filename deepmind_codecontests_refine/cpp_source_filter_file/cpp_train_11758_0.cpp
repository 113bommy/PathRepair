#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<sstream>


#define reps(i,f,n) for(int i = f; i < int(n); i++)
#define rep(i,n) reps(i,0,n)
typedef __int64 ll;

using namespace std;

int main(void){
	
	int n;

	while(scanf("%d", &n), n){
		ll p[60]={0};
		bool ans = false;
		vector<int> x[50];
		
		rep(i,60)
			p[i] = (ll)(1)<<i;
		
		rep(i,n){
			int m;
			scanf("%d", &m);
			rep(j,m){
				int t;
				scanf("%d", &t);
				x[t].push_back(i);
			}
		}
		
		reps(i,1,31){
			ll b = 0;
			rep(j,x[i].size())
				b |= p[x[i][j]];
			rep(j, x[i].size())
				p[x[i][j]] = b;
				
			if(b == ((ll)1<<n)-1){
				ans = true;
				printf("%d\n", i);
				break;
			}
		}
		if(!ans){
			puts("-1");
		}
	}
	return 0;
}