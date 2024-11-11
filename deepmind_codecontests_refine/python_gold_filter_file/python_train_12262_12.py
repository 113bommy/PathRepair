from math import gcd
N = int(input())
ans = sum([gcd(gcd(i,j),k) for i in range(1,N+1) for j in range(1,N+1) for k in range(1,N+1)])
print(ans)
