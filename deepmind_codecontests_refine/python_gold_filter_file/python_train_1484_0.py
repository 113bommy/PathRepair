import math
n = int(input())
l = list(map(int,input().split()))[:n]
t =[0]*n
t[n-1]=l[n-1]
for i in range(n-1):
    t[n-i-2]=math.gcd(t[n-i-1],l[n-i-2])
s = l[0]*t[1]//t[0]
for i in range(1,n-1):
    s = math.gcd(s,(l[i]*t[i+1])//math.gcd(l[i],t[i+1]))
print(s)
