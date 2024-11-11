s=int(input())
c=list(map(int,input().split()))
c.sort()
g=0
a=[]
m=c[s-1]
a.append(m)
i=1
while c[s-i]==m and s-i>=0:
    i+=1
for t in range(0,s-i+1):
    if c[-i-t]!=m:
        m=c[-i-t]
        g=1
        a.append(m)
    else:
        if g==1:
            a.insert(0,m)
            g=2
print(len(a))
print(*a)