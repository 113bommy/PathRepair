from collections import deque

N, L = map( int, input().split() )
T = []
V = []
for i in range( N ):
  t, v = map( int, input().split() )
  T.append( t )
  V.append( v )

dq = deque()
ct, cv = 0.0, 0.0
for i in range( N ):
  while cv + V[ i ] > L:
    ft, fv = dq[ 0 ]
    take = min( cv + V[ i ] - L, fv )
    ct, cv = ( ct * cv - ft * take ) / ( cv - take ), cv - take
    if take == fv:
      dq.popleft()
    else:
      dq[ 0 ] = [ ft, fv - take ]
  ct, cv = ( ct * cv + T[ i ] * V[ i ] ) / L, L
  print( "%.7f" % ct )
  while len( dq ):
    bt, bv = dq[ len( dq ) - 1 ]
    if bt < T[ i ]: break
    T[ i ], V[ i ] = ( T[ i ] * V[ i ] + bt * bv ) / ( V[ i ] + bv ), V[ i ] + bv
    dq.pop()
  dq.append( [ T[ i ], V[ i ] ] )
