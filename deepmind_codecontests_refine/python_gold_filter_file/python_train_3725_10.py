import math

A,B,H,M = map(int,input().split())
C2 = A**2+B**2-2*A*B*math.cos(math.radians(abs((30*H+M*0.5)-6*M)))
print(C2**0.5)