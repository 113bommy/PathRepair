import sys

n,m=map(int,sys.stdin.readline().split())

L=list(map(int,sys.stdin.readline().split()))

R=[0]*n
K=[0]*n
p=0

for i in range(1,n):
    if(L[i]<L[i-1]):
        for j in range(p,i):
            R[j]=i
        p=i
for j in range(p,n):
    R[j]=n
p=0
for i in range(1,n):
    if(L[i]>L[i-1]):
        for j in range(p,i):
            K[j]=i
        p=i
for j in range(p,n):
    K[j]=n
for i in range(m):
    x,y=map(int,sys.stdin.readline().split())
    x-=1
    y-=1
    r=R[x]
    if(r>=y):
        sys.stdout.write("Yes\n")
        continue
    e=K[r]
    if(e>y):
        sys.stdout.write("Yes\n")
        continue
    sys.stdout.write("No\n")
    
