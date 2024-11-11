n,k=map(int,input().split())
s=input()
d=s+s[::-1]
d=d[::-1]
r=d[:n]
e=d[:n]
for i in range(n):
    e=e[1:]+d[n+i]
    r=min(r,e)
t=1
qo=r[0]
for i in range(1,n):
    if qo==r[i]:
        t+=1
    else:
        break
r=r[::-1]
for i in range(k-1):
    p=r+r[n-t:]
    p=p[::-1]
    p=p[:n]
    if r==p:
        break
    else:
        r=p[::-1]
        t+=t
print(r[::-1])