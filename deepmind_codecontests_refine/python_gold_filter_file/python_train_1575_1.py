import math
f=math.factorial
n,m,k=map(int,input().split())
print(f(n-1)//f(k)//f(n-k-1)*m*(m-1)**k%998244353)