n=int(input())
l1=r1=l0=r0=0

for i in range(n):
    l,r=map(int,input().split())
    l1+=l
    r1+=r
l0=n-l1
r0=n-r1

if (l0==0 and r0==0) or (l1==n and r1==n):
    print(0)
else:
    if r1==n and n-l1<l1:
        print(l0)
    elif l1==n and n-r1<r1:
        print(r0)
    elif r0==0 and n-l0<l0:
        print(l1)
    elif l0==0 and n-r0<r0:
        print(r1)
    elif l1==r1 and l1+r1<=l0+r0:
        print(l1+r1)
    elif l0==r0 and l0+r0<=l1+r1:
        print(l0+r0)
    elif l1+r0<l0+r1:
        print(l1+r0)
    elif l0+r1<l1+r0:
        print(l0+r1)
    