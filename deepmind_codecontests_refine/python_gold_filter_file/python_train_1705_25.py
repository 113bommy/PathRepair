n,m=map(int,input().split())
print(min(n+1,m+1))
for i in range(min(n+1,m+1)):
    print(min(n,m)-i,i)