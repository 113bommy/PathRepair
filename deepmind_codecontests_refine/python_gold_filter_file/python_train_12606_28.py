n,m=map(int,input().split())
l=[]
for j in range(n):
    s=list(map(int,input().split()))
    s.append(s[0]-s[1])
    s.reverse()
    l.append(s)
    j+=1
l.sort()
l.reverse()
k=0
a=0
while k<n:
    a=a+l[k][2]
    k+=1
b=a-m
i=0
d=0
while i<n:
    if d>=b:
        break
    else:
        d=d+l[i][0]
        i+=1
if i==n and d<b:
     print(-1)
else:
     print(i)