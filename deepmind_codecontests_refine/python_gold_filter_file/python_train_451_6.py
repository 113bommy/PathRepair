l0=0
l1=0
r0=0
r1=0
for i in range(int(input())):
    l,r = list(map(int,input().split()))
    if l==0:
        l0+=1
    else:
        l1+=1
    if r==0:
        r0+=1
    else:
        r1+=1
lmin = min(l0,l1)
rmin = min(r0,r1)
print(lmin+rmin)
