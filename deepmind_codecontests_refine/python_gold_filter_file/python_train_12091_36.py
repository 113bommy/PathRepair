n,m,k=map(int,input().split())
v=list(map(int,input().split()))
m1=0
m2=0
for i in range(n):
    if v[i]>=m1:
        m2=m1
        m1=v[i]
    else:
        m2=max(m2,v[i])
print((m//(k+1)*m2+(m-m//(k+1))*m1))