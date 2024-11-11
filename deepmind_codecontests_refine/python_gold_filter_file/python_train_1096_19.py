n=int(input())
m=list(map(int,input().split()))
mini=min(m)
maxi=max(m)
x=m.index(mini)
y=m.index(maxi)
if y>x:
    temp=x
    x=y
    y=temp
if x-y==n-1:
    print(n-1)
else:
    if y>=n-x:
        print(x)
    else:
        print(n-y-1)
    