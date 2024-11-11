n=int(input())
from collections import Counter
a=Counter(list(map(int,input().split())))
l=[]
ll=[]
ans=0
for i in a:
    if a[i]>=2:
        l.append(i)
    if a[i]>=4:
        ans=max(ans,i*i)
l.sort(reverse=True)
if len(l)<2:
    print(0)
else:
    print(max(l[0]*l[1],ans))
