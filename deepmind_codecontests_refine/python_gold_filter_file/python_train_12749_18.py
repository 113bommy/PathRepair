import itertools
import math
x = lambda: map( int, input().split() )
mega = lambda d: d + 1e9

def main():
    n, r = x()
    a = list( x() )
    a.sort()
    d = ( a[0] > 0 ) * a[0]
    #print(d)
    for i in range( 1, n ):
        d = max( ( a[i] - a[i - 1] ) / 2, d )
    d = max( d, ( a[n - 1] < r ) *  ( r - a[n - 1] ) )
    print(d)

main()
