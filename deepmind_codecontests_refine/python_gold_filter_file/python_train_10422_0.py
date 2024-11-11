n=input()
n=int(n)
l=[]
r=[]
for i in range(n):
    s=input().split()
    s=list(map(int,s))
    l.append(s[0])
    r.append(s[1])
l=sorted(l)
r=sorted(r)
res=0
for i in range(n):
    res+=max(l[i],r[i])+1
print(res)