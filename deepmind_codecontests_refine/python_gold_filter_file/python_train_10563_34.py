from collections import defaultdict
d=defaultdict(list)
n,m=map(int,input().split())
for i in range(m):
    x,y=map(str,input().split())
    if len(x)>len(y):
        d[x].append(y)
    else:
        d[x].append(x)
        
s=list(map(str,input().split()))
for i in range(n):
    print(*d[s[i]],end=" ")