n,m=map(int,input().split())
print(n+m-1)
if m<=n:
    for i in range(1,n+1):
        print(i,1)
    for j in range(2,m+1):
        print(i,j)
else:
    for i in range(1,m+1):
        print(1,i)
    for j in range(2,n+1):
        print(j,i)

