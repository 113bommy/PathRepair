from bisect import bisect_right
s,b=map(int,input().split(' '))
a=list(map(int,input().split(' ')))
l=[]
for _ in range(b):
    d, g = map(int, input().split(' '))
    l.append([d,g])
l=[[-1,0]]+sorted(l)
for i in range(1,len(l)):
    l[i][1]+=l[i-1][1]
ans=[]
value=[v[0] for v in l]
ans=[l[bisect_right(value,v)-1][1] for v in a]
for aa in ans:
    print(aa,end=' ')