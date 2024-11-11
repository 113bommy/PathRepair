#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <cmath>
#include <cassert>
#include <cstdio>

using namespace std; using namespace placeholders;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector< int > VI;
typedef vector< vector< int > > VVI;
typedef vector< string > VS;
typedef stringstream SS;
typedef pair< int, int > PII;
typedef vector< pair< int, int > > VPII;
#define VT( T ) vector< T >
#define VVT( T ) vector< vector< T > >
#define LIM( T ) numeric_limits< T >

template < typename T > inline istream& operator>>( istream &s, vector< T > &v ){ for ( T &t : v ) { s >> t; } return s; }
template < typename T > inline ostream& operator<<( ostream &s, const vector< T > &v ){ for ( int i = 0; i < int( v.size() ); ++i ){ s << ( " " + !i ) << v[i]; } return s; }
template < typename T > inline T fromString( const string &s ) { T res; istringstream iss( s ); iss >> res; return res; };
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };

#define REP2( i, n ) REP3( i, 0, n )
#define REP3( i, m, n ) for ( int i = ( int )( m ); i < ( int )( n ); ++i )
#define GET_REP( a, b, c, F, ... ) F
#define REP( ... ) GET_REP( __VA_ARGS__, REP3, REP2 )( __VA_ARGS__ )
#define FOR( e, c ) for ( auto &e : c )
#define ALL( c ) ( c ).begin(), ( c ).end()
#define AALL( a, t ) ( t* )a, ( t* )a + sizeof( a ) / sizeof( t )
#define DRANGE( c, p ) ( c ).begin(), ( c ).begin() + p, ( c ).end()

#define SZ( v ) ( (int)( v ).size() )
#define PB push_back
#define EM emplace
#define EB emplace_back
#define BI back_inserter

#define EXIST( c, e ) ( ( c ).find( e ) != ( c ).end() )

#define MP make_pair
#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	for ( int K; cin >> K && K; )
	{
		string S, T;
		cin >> S >> T;

		VI a, b;
		transform( ALL( S ), BI( a ), bind( minus< int >(), _1, '0' ) );
		transform( ALL( T ), BI( b ), bind( minus< int >(), _1, '0' ) );

		VI c;
		transform( ALL( a ), b.begin(), BI( c ), []( const int x, const int y ){ return ( y - x + 10 ) % 10; } );
		c.PB( 0 );

		VI ds;
		adjacent_difference( ALL( c ), BI( ds ) );
		transform( ALL( ds ), ds.begin(), []( const int d ){ return ( d + 10 ) % 10; } );
		ds.erase( remove( ALL( ds ), 0 ), ds.end() );
		sort( ALL( ds ) );

		int res = SZ( ds );
		do
		{
			VI csum;
			partial_sum( ALL( ds ), BI( csum ) );
			res = min( res, SZ( ds ) - count_if( ALL( csum ), []( const int x ){ return x % 10 == 0; } ) );
		}
		while ( next_permutation( ALL( ds ) ) );

		cout << res << endl;
	}

	return 0;
}