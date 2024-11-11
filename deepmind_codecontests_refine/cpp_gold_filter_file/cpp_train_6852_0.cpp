#include <bits/stdc++.h>
using namespace std;
using lld = int64_t;
const int N = 100000 + 5;

int a[ N ], s[ N ];
lld bit[ N << 1 ];

lld query( int p ) {
	lld ret = 0;
	while ( p ) {
		ret += bit[ p ];
		p -= p & (-p);
	}
	return ret;
}
void add( int p, int x ) {
	while ( p < N + N ) {
		bit[ p ] += x;
		p += p & (-p);
	}
}

lld calc( int m, int n ) {
	for ( int i = 1 ; i <= n ; ++ i )
		if ( a[ i - 1 ] >= m ) s[ i ] = s[ i - 1 ] + 1;
		else s[ i ] = s[ i - 1 ] - 1;
	memset( bit, 0, sizeof( bit ) );
	lld ret = 0;
	for ( int i = 0 ; i <= n ; ++ i ) {
		ret += query( s[ i ] + N );
		add( s[ i ] + N, 1 );
	}
	return ret;
}

int main() {
	int n; scanf( "%d", &n );
	for ( int i = 0 ; i < n ; ++ i )
		scanf( "%d", a + i );
	lld tot = 1LL * n * ( n + 1 ) / 2;
	int l = 1, r = 1000000001;
	while ( r - l > 1 ) {
		int m = ( l + r ) >> 1;
		if ( calc( m, n ) * 2 >= tot ) l = m;
		else r = m;
	}
	cout << l << '\n';
	return 0;
}
