#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
#define MAXN 200006
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
int n , m , q;

int fa[MAXN];
int find( int x ) {
	return x == fa[x] ? x : fa[x] = find( fa[x] );
}
struct dl{
	int u , v;
} d[MAXN] ;
int cnt , c;

signed main( ) {
	cin >> n >> m >> q;
	for( int i = 1 ; i <= n ; ++ i ) fa[i] = i;
	for( int i = 1 , u , v , c ; i <= q ; ++ i ) {
		scanf("%lld%lld%lld",&u,&v,&c);
		++ u , ++ v;
		if( !c ) {
			fa[find( u )] = find( v );
		} else {
			d[++ cnt] = (dl) { u , v };
		}
	}
	for( int i = 1 , u , v ; i <= cnt ; ++ i ) {
		if( find( d[i].u ) == find( d[i].v ) )
			return puts("No") , 0;
	}
	for( int i = 1 ; i <= n ; ++ i ) if( fa[i] == i )
		++ c;
	int ed = m - n + c;
	if( !cnt ) return puts( ( ed >= c - 1 && ed <= c * ( c - 1 ) / 2 ) ? "Yes" : "No" ) , 0;
	else return puts( ( ed >= max( c , 3ll ) && ed <= c * ( c - 1 ) / 2 ) ? "Yes" : "No" ) , 0;
}