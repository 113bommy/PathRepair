import math
n=int(input())
z=list(map(int,input().split()))
l=0
for i in z:
    l=math.gcd(l,i)
if(l not in z):
    print(-1)
else:
    print(l)