from math import *
N = int(input())
if N==2: print(6)
elif floor(sqrt(N))**2==N or floor(sqrt(N+1))**2==N+1: print(4*ceil(sqrt(N)))
else:
    if N-floor(sqrt(N))**2<=floor(sqrt(N)): print(4*floor(sqrt(N))+2)
    else: print(4*floor(sqrt(N))+4)
