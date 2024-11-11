N, Q = map(int, input().split())
l=[None]*N
l[0]=[1,1,0]
for i in range(1,N):
    a,b=map(int,input().split())
    l[i]=[b,a,0]
l.sort()
for i in range(Q):
    p,x=map(int,input().split())
    l[p-1][2]+=x
t=[l[0][2]]+[None]*(N-1)
for i in range(1,N):
    t[i]=t[l[i][1]-1]+l[i][2]
print(*t)