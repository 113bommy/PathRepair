from sys import stdin
t=int(stdin.readline().rstrip())
while t>0:
    a,b=map(int,stdin.readline().split())
    c=0
    k=0
    if a==b:
        k=0
    elif a>b:
        k=a-b
    else:
        k=b-a
    if k>=5:
        c+=k//5
        k=k%5
    if k>=2:
        c+=k//2
        k=k%2
    if k>=1:
        c+=k
        k=0
    print(c)
    t-=1