#!/usr/bin/env python

def toBin( i ):
    n = ""
    while i > 0:
        n += str( i % 2 )
        i = i // 2

    return int( n[ :: -1 ] )

def main( ):
    n = int( input( ) )
    i = 1
    while toBin( i ) <= n:
        i += 1
    print( i - 1 )



if __name__ == '__main__':
    main( )

