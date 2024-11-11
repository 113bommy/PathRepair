n,m=map(int,input().split())
#print(n,m)
steps=(n//2)+(n%2)
#print(steps)
if n<m:
    print(-1)
elif n==m:print(n)
elif steps%m==0:
    print(steps)
elif steps!=m:
    x=steps%m
    if (m-x)<=(n//2):
        steps=steps+m-x
        print(steps)
else:
    print(-1)