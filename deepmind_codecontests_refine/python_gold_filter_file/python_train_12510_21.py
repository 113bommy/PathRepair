import math
from collections import defaultdict
ml=lambda:map(int,input().split())
ll=lambda:list(map(int,input().split()))
ii=lambda:int(input())
ip=lambda:list(input())

"""========main code==============="""

n,k=ml()
ans=0;
for i in range(1,1000001):
    val=(i*(i+1))//2
    if(val-(n-i)==k):
        ans=n-i
print(ans)        