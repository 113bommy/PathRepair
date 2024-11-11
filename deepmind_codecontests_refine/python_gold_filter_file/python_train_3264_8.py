import copy
l=lambda :map(int,input().split())
n,m=l()
t=n
p=sorted([*l()])
p_=p.copy()
min=0
max=0
while n>0:
    min+=p[0]
    p[0]-=1
    n-=1
    if p[0]==0:
        p.pop(0)
while t>0:
    max += p_[-1]
    p_[-1] -= 1
    p_=sorted(p_)
    t -= 1
print(max,min)