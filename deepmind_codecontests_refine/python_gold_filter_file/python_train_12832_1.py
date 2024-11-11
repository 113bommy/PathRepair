from collections import Counter
l=[]
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    d=dict(Counter(a))
    c=[0]*101
    for x in d:
        for y in d:
            c[x+y]=min(d[x],d[y])+c[x+y]
    m=max(c)//2
    l.append(m)
for i in l:
    print(i)