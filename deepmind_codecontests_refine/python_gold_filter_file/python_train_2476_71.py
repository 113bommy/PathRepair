import math
A,B,C,D = map(int,input().split())
print("Yes" if math.ceil(C/B) <= math.ceil(A/D) else "No")