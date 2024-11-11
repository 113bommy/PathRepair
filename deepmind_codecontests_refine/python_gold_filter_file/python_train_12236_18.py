from sys import stdin, stdout

n, a, b = map( int, stdin.readline().rstrip().split() )

stdout.write( str((a + b) % n or n) + "\n" )