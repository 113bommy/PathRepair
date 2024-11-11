n,k=map(int,input().split())
r=n%k
s=min([r,k-r])
print(s)