from sys import stdin
t=int(stdin.readline())
for z in range(t):
    x,y=map(int,stdin.readline().strip().split())
    a,b=map(int,stdin.readline().strip().split())
    d1=max(x,y)-min(x,y)
    a1=d1*a
    sol1=min(x,y)*b
    sol2=2*min(x,y)*a
    ans=min(sol2,sol1)
    print(ans+a1)

