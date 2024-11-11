n,v=map(int,input().split())

if v<n-1:
    c=v
    for i in range(2,n+1-v):
        c+=i
else:
    c=n-1
print(c)