## debugging nichamp's code

import math
t=int(input())
ans=[]

while(t!=0):
    t=t-1
    n,k = map(int,input().split(" "))
    li2=list( map(int,input().split(" ")))
    li2.sort(reverse=True)
    
    el = li2[k-1]
    cnt = li2.count(el)
    idx1 = li2.index(el)
    pick = k - idx1
    ncr = math.factorial(cnt) // (math.factorial(pick) * math.factorial(cnt-pick))
    ans.append(ncr)

for i in ans:
    v=int(i%((10**(9))+7))
    print(v)
