x,n=map(int,input().split())
S=map(int, input().split())
K=(list(range(0,102)))
for i in S:
    K.remove(i)
L=[]
for i in K:
    L.append(abs(x-i))
m=min(L)
ind_m=L.index(m)
print(K[ind_m])