a=int(input())
b=list(map(int,input().split()))
c=b.copy()
d=b.copy()
for i in range(a):
    if i==0:
        c[i]=1
    elif b[i-1]<=b[i]:
        c[i]=c[i-1]+1
    else:
        c[i]=1
for i in range(a):
    if i==0:
        d[i]=1
    elif b[::-1][i-1]<=b[::-1][i]:
        d[i]=d[i-1]+1
    else:
        d[i]=1
print(max(c[i]+d[::-1][i] for i in range(a))-1)