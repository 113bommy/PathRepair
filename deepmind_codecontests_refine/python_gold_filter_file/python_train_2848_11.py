n,k=map(int,input().split())
l=list(map(int,input().split()))
k = k-1
i = n-1
while l[k] == l[i] and i>=0:
    i -= 1

if i<=k:
    print(i+1)
else:
    print(-1) 