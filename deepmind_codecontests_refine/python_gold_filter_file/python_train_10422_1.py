n=int(input())
l=[]
r=[]
for i in range(n):
    a,b=map(int,input().split())
    l.append(a)
    r.append(b)
r=sorted(r)
l=sorted(l)
ss=n
for i in range(n):
    ss+=max(l[i],r[i])
print(ss)