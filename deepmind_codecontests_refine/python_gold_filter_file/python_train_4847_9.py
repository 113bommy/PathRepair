N = int( input() )
if N == 0:
  exit( print( 1 ) )
print( pow( 3, N - 1, int( 1e6 + 3 ) ) )