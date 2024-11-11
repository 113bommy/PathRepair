r = input().split(' ')
n = int( r[ 0 ] )
k = int( r[ 1 ] )

if n * ( n - 1 ) >> 1 <= k:
    print( 'no solution' )
else:
    for i in range( 0 , n ):
        print( 0 , i + 1 )
