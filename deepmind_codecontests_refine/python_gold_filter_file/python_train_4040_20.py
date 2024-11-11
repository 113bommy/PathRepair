from heapq import*
(N,M),*t=[map(int,s.split())for s in open(0)]
z,*q=[0]*50*M
v=[[]for _ in q]
for a,b in t:v[a-1]+=b,
for i in v[:M]:[heappush(q,-j)for j in i];z-=heappop(q)
print(z)