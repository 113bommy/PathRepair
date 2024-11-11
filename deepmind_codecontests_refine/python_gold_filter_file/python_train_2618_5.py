"""
import bisect
shop=int(input())
price=list(map(int,input().split()))
q=int(input())
price.sort()
for i in range(q):
            m=int(input())
            k=bisect.bisect_right(price,m,0,shop)
            print(len(price)-len(price[k:]))
"""
"""
import math
n,k=map(int,input().split())
lis=[]
for i in range(n):
            p,t=map(int,input().split())
            lis.append([p,t])
lis=sorted(lis,key=lambda x,y:(cmp(x[0],y[0]),cmp(y[1],x[1])),reverse=True)
m=lis[k-1]
print(lis.count(m))
print(lis)
"""

n,m=map(int,input().split())
r=m/n
cnt=0
while(r%2==0):
            cnt+=1
            r/=2
while(r%3==0):
            cnt+=1
            r/=3
if(r==1):
            print(cnt)
else:
            print(-1)
