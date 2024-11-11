t=int(input())
s=input()
p=[int(s) for s in s.split()]
f=0
m=0
n=0
p.sort()
for i in range(t-1,-1,-1):
    if p[i]%2==0:
        n+=p[i]
    elif f==0:
        m=p[i]
        f=1
    elif f==1:
        n+=p[i]
        n+=m
        f=0
        m=0
print(n)
