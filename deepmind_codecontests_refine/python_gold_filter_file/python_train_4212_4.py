n=int(input())
p=list(map(float,input().split()))
p.sort()
p.reverse()
p0=1
p1=0
for i in range(n):
    if p1<p1*(1-p[i])+p0*p[i]:
        tmp=p0
        p1=p1*(1-p[i])+p0*p[i]
        p0=tmp*(1-p[i])
print(p1)