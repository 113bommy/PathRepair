import sys
from collections import Counter
sys.setrecursionlimit(10**7)


n=int(input())
x=set()
for i in input().split():
    x.add(int(i))
m=len(x)
if m==1:
    ans=0
elif m==2:
    aa=abs(x.pop()-x.pop())
    if aa%2==1:
        ans=aa
    else:
        ans=aa//2
    
elif m==3:
    s,t,u=x.pop(),x.pop(),x.pop()
    s,t,u=max(s,t,u),(s+t+u-max(s,t,u)-min(s,t,u)),min(s,t,u)
    if abs(s-t)==abs(t-u):
        ans=abs(s-t)
    else:
        ans=-1
else:
    ans=-1
print(ans)