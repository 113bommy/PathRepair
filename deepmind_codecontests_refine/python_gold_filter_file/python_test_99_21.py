from sys import stdin
input=stdin.readline
rn=lambda:int(input())
rns=lambda:map(int,input().split())
rl=lambda:list(map(int,input().split()))
rs=lambda:input().strip()
YN=lambda x:print('YES') if x else print('NO')
ceil_div=lambda a,b:-(-a//b)
mod=10**9+7

for _ in range(rn()):
    x,n=rns()
    m=n%4
    b=n-m
    if x%2==0:
        a=[x,x-b-1,x+1,x+b+4]
    else:
        a=[x,x+b+1,x-1,x-b-4]
    print(a[m])