n=int(input())
l=list(map(int,input().split()))
from itertools import combinations
from copy import deepcopy
answ=[]
for i in combinations(l,2):
    ls=deepcopy(l)
    for j in i:
        ls.remove(j)
    ls.sort()
    ans=0
    for i in range(0,(len(ls)-1),2):
        ans+=ls[i+1]-ls[i]
    answ.append(ans)
print(min(answ))
