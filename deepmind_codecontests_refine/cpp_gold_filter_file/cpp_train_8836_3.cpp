#include<stdio.h>
#include<algorithm>


using namespace std ;



int ans ;



bool ok[ 1000 ][ 1000 ][ 1000 ] ;


int aa[ 3 ] ;


#define a aa[ 0 ]
#define b aa[ 1 ]
#define c aa[ 2 ]


int main()
{
	int n ;
	scanf( "%d" ,&n ) ;


	while( n-- )
	{
		scanf( "%d %d %d" ,&a ,&b ,&c ) ;


		--a ;
		--b ;
		--c ;


		sort( aa ,aa + 3 ) ;


		if( ok[ a ][ b ][ c ] )
		{
			++ans ;
		}
		
		else
		{
			ok[ a ][ b ][ c ] = true ;
		}
	}



	printf( "%d\n" ,ans ) ;


	return 0 ;
}