n=int(input())
l=[int(i) for i in input().split()]
s=sum(l)
res=[]
from collections import Counter 
c=Counter(l)
for i in range(n):
    curr=s-l[i]
    if c[curr/2] :
        if l[i]*3==s:
            if c[l[i]]>1:
              #  print('hi')
                res.append(i+1)
        else:
            res.append(i+1)
print(len(res))
print(*res)