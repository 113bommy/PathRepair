import math
N, K = map(int, input().split())
print( 1 + math.ceil((N-K) / (K-1)) )