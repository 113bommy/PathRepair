#include <iostream>
#include <cstdio>
#include <queue>
using namespace std ;
const int N = 200010 ; 
struct rec{
	int a,b,id ;
	friend inline bool operator < (const rec x,const rec y){
		return 1ll*x.a*y.b < 1ll*x.b*y.a ;  
	}
};
priority_queue<rec> q ;
int n,fa[N],f[N],cnt[N][2] ; 
inline int get(int x){
	return x == f[x] ? x : f[x] = get(f[x]) ; 
}
int main(){
	//freopen("in.txt","r",stdin) ; 
	cin >> n ;
	for(int i = 2 ; i <= n ; i++) scanf("%d",&fa[i]),f[i] = i ; 
	for(int i = 1 ; i <= n ; i++){ int val ; scanf("%d",&val) ; cnt[i][val]++ ; }
	for(int i = 2 ; i <= n ; i++) q.push((rec){cnt[i][0],cnt[i][1],i}) ;
	f[1] = 1 ; long long ans = 0 ;
	while(!q.empty()){
		rec x = q.top() ; q.pop() ; 
		int id = get(x.id),a = x.a,b = x.b ;  
		if(cnt[id][0] != a || cnt[id][1] != b) continue ;
		int y = get(fa[id]) ;
		ans += 1ll*cnt[y][1]*a ;
		cnt[y][0] += a ; cnt[y][1] += b ;
		f[id] = y ;
		if(y > 1) q.push((rec){cnt[y][0],cnt[y][1],y}) ; 
	}
	cout << ans << endl; 
	return 0 ; 
}